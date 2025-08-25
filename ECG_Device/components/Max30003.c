#include "Max30003.h"

static const char TAG[] = "MAX30003";
#pragma region MAX30003
struct MAX30003_context_t
{
    SPI_config cfg;                 ///< Configuration by the caller.
    spi_device_handle_t spi_handle; ///< SPI device handle
    SemaphoreHandle_t INTB2Bsem;    ///< Semaphore for INTB and INT2B ISR
};

esp_err_t Max30003_init(MAX30003_handle_t *out_handle, SPI_config *config_pin)
{
    esp_err_t err = ESP_OK;
    MAX30003_handle_t Max_handle = malloc(sizeof(struct MAX30003_context_t));
    if (Max_handle == NULL)
    {
        return ESP_ERR_NO_MEM;
    }
    // Sao chép cấu hình
    memcpy(&Max_handle->cfg, config_pin, sizeof(SPI_config));
    SPIsetting _cfg = {
        ._clock = MAX30003_SPI_SPEED,
        ._bitOrder = SPI_MSBFIRST,
        ._dataMode = SPI_MODE0};
    SPI_init_bus(&Max_handle->cfg, 32);

    *out_handle = Max_handle; // gán ngược ra ngoài
    err = SPI_add_device(Max_handle->cfg.CS_pin, &_cfg, &Max_handle->spi_handle);
    if (err != ESP_OK)
    {
        if (Max_handle->spi_handle)
        {
            spi_bus_remove_device(Max_handle->spi_handle);
            Max_handle->spi_handle = NULL;
        }
        free(Max_handle); // giải phóng bộ nhớ
    }
    return err;
}
#pragma region MAX30003_read
esp_err_t max30003RegRead(MAX30003_handle_t ctx, uint8_t Reg_address, uint8_t *buff)
{
    uint8_t spiTxBuff[4] = {(Reg_address << 1) | RREG, 0, 0, 0};
    spi_transaction_t trans = {
        .length = 8 * 4, // 4 byte = 32 bit (1 byte lệnh + 3 byte data)
        .tx_buffer = spiTxBuff,
        .rx_buffer = buff,
    };
    // spi_transaction_t *pTrans = &trans;
    // spi_device_queue_trans(ctx->spi, &trans, portMAX_DELAY);
    // esp_err_t err = spi_device_get_trans_result(ctx->spi, &pTrans, portMAX_DELAY);
    gpio_set_level(ctx->cfg.CS_pin, 0);
    esp_err_t err = spi_device_transmit(ctx->spi_handle, &trans);
    gpio_set_level(ctx->cfg.CS_pin, 1);
    return err;
}
#pragma endregion MAX30003_read
#pragma region MAX30003_write
esp_err_t max30003RegWrite(MAX30003_handle_t ctx, uint8_t WRITE_ADDRESS, uint32_t data)
{

    uint8_t TxBuff[4];
    // Byte 0: Command (ghi thanh ghi)
    TxBuff[0] = (WRITE_ADDRESS << 1) | WREG;
    // 3 byte data (24 bit)
    TxBuff[1] = (data >> 16) & 0xFF;
    TxBuff[2] = (data >> 8) & 0xFF;
    TxBuff[3] = data & 0xFF;

    spi_transaction_t trans = {
        .length = 32, // 4 byte = 32 bits
        .tx_buffer = TxBuff,
    };

    gpio_set_level(ctx->cfg.CS_pin, 0);
    esp_err_t err = spi_device_transmit(ctx->spi_handle, &trans);
    gpio_set_level(ctx->cfg.CS_pin, 1);
    return err;
}
#pragma endregion MAX30003_write
bool max30003ReadInfo(MAX30003_handle_t ctx)
{
    uint8_t readBuff[4];

    max30003RegRead(ctx, INFO, readBuff);
    // printf("INFO Reg Raw: %02X %02X %02X %02X\n",
    //    readBuff[0], readBuff[1], readBuff[2], readBuff[3]);
    if ((readBuff[1] & 0xf0) == 0x50)
    { // chỉ nhận tín hiệu mức cao trả giá trị nhận vào 0101rev[19,16]

        printf("max30003 is ready");
        printf("Rev ID : %d\n", (readBuff[1] & 0xF0));
        return true;
    }
    else
    {

        printf("max30003 read info error\n");
        return false;
    }
}
#pragma endregion MAX30003

#pragma region SPICLASS
esp_err_t SPI_init_bus(SPI_config *config_pin, uint8_t max_transfer)
{

    esp_err_t ret;
    ESP_LOGI(TAG, "Initializing bus SPI...");
    spi_bus_config_t buscfg = {
        .miso_io_num = config_pin->MISO_pin,
        .mosi_io_num = config_pin->MOSI_pin,
        .sclk_io_num = config_pin->SCK_pin,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = max_transfer,
    };
    // Initialize the SPI bus
    ret = spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
    return ret;
}
esp_err_t SPI_add_device(gpio_num_t _CS, SPIsetting *cfg, spi_device_handle_t *spi_handle)
{
    esp_err_t ret;
    ESP_LOGI(TAG, "Adding SPI device...");

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = cfg->_clock,
        .mode = cfg->_dataMode, // SPI_MODE0..3
        .command_bits = 0,
        .spics_io_num = -1,
        // .pre_cb = cs_low, // trước khi bắt đầu truyền dữ liệu, CS ở mức thấp
        // .post_cb = cs_high, // sau khi truyền dữ liệu, CS đưa lên mức cao
        .queue_size = 1,
        .input_delay_ns = 500,
        .flags = SPI_DEVICE_POSITIVE_CS,
    };

    ret = spi_bus_add_device(SPI2_HOST, &devcfg, spi_handle);
    gpio_config_t cs_cfg = {
        .pin_bit_mask = (1ULL << _CS),
        .mode = GPIO_MODE_OUTPUT,
    };
    gpio_config(&cs_cfg);
    gpio_set_level(_CS, 1);
    return ret;
}
// static void IRAM_ATTR cs_low(spi_transaction_t *trans) // chuyển đổi ngữ cảnh an toàn khi có callback
// {
//     gpio_set_level(CS_PIN, 0);
// }
// static void IRAM_ATTR cs_high(spi_transaction_t *trans)
// {
//     gpio_set_level(CS_PIN, 1);
// }
#pragma endregion SPICLASS
