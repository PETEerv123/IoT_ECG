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
void max30003Begin(MAX30003_handle_t ctx)
{
    max30003SwReset(ctx); // Khởi động lại thiết bị
    vTaskDelay(pdMS_TO_TICKS(100));

    // Cấu hình thanh ghi CNFG_GEN
    // Bật chức năng phát hiện lead-on và cài đặt ngưỡng phát hiện điện cực 0x802CB 0x8141B 0x8151B 0x8155B
    max30003RegWrite(ctx, CNFG_GEN, 0x81A1B); // Dòng điện DC Lead-Off: 10nA, ngưỡng phát hiện: VMID ± 300mV Bia 200M
    // 0x81D53 50M  100nA 300mV
    // 0x81D57 100M 100nA 300mV
    // 0x81D5B 200M 100nA 400mV
    // 0x81D1B 200M 100nA 300mV
    //  0x81917 100M 5nA 300mV
    // 0x81B1B 200M 20nA  300mV 0x81A1B

    // 0x81A00 Non Bias
    vTaskDelay(pdMS_TO_TICKS(100));
    max30003RegWrite(ctx, MNGR_INT, 0x780010);
    vTaskDelay(pdMS_TO_TICKS(100));
    max30003RegWrite(ctx, MNGR_DYN, 0xBF0000);
    vTaskDelay(pdMS_TO_TICKS(100));
    // Cấu hình hiệu chuẩn (Calibration) CNFG_CAL
    // Cài đặt tín hiệu chuẩn để kiểm tra đường tín hiệu
    // max30003RegWrite(CNFG_CAL, 0x720000);  //   Calibration Source Magnitude Selection (VMAG)  = 0.50mV  || Calibration Source Frequency 256Hz
    // Cấu hình MUX đầu vào CNFG_EMUX 0x304800 0x700800 600800
    // Kết nối đường tín hiệu ECG vào ngõ vào MUX
    // delay(100);
    max30003RegWrite(ctx, CNFG_EMUX, 0x0B0000); // Chọn ngõ vào ECGP và ECGN
    vTaskDelay(pdMS_TO_TICKS(100));

    // Cấu hình ECG CNFG_ECG
    // Cài đặt tốc độ lấy mẫu và các bộ lọc để tối ưu hóa chất lượng tín hiệu 0x805000 , 837000 512 Hz, GAIN=160, DLPF=150 Hz , 0x836002 512 Hz, GAIN=160, DLPF = 40 Hz
    max30003RegWrite(ctx, CNFG_ECG, 0x835000); //
    vTaskDelay(pdMS_TO_TICKS(100));
    // 512Hz, Gain=40, DLPF=40Hz, DHPF=0.5Hz //0x815000
    // Cấu hình CNFG_RTOR1
    max30003RegWrite(ctx, CNFG_RTOR1, 0x3FB400); // 0x5FC600 0x3fc600 0x3FA300
    vTaskDelay(pdMS_TO_TICKS(100));
    max30003RegWrite(ctx, EN_INT, 0x800403); // phát hiện sóng RR
    vTaskDelay(pdMS_TO_TICKS(100));
    max30003Synch(ctx);
    vTaskDelay(pdMS_TO_TICKS(100));
}
void max30003SwReset(MAX30003_handle_t ctx)
{
    max30003RegWrite(ctx, SW_RST, 0x000000);
    vTaskDelay(pdMS_TO_TICKS(100));
}

void max30003Synch(MAX30003_handle_t ctx)
{
    max30003RegWrite(ctx, SYNCH, 0x000000);
}
signed long MAX30003_getEcgSamples(MAX30003_handle_t ctx)
{
    uint8_t regReadBuff[4];
    max30003RegRead(ctx, ECG_FIFO, regReadBuff);

    unsigned long data0 = (unsigned long)(regReadBuff[1]);
    data0 = data0 << 24;
    unsigned long data1 = (unsigned long)(regReadBuff[2]);
    data1 = data1 << 16;
    unsigned long data2 = (unsigned long)(regReadBuff[3]);
    data2 = data2 >> 6;
    data2 = data2 & 0x03;

    unsigned long data = (unsigned long)(data0 | data1 | data2);
    signed long ecgdata = (signed long)(data);
    return ecgdata;
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
