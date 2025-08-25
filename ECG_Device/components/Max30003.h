#ifndef _Max30003_H
#define _Max30003_H

#include "stdio.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "string.h"
/*SPI CLASS*/
#pragma region SPICLASS
#define MAX30003_SPI_SPEED 3000000

#define SPI_LSBFIRST 0
#define SPI_MSBFIRST 1

#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3

#define default_clock 1 // 1MHz

typedef struct
{
  uint32_t _clock;
  uint8_t _bitOrder;
  uint8_t _dataMode;
} SPIsetting;
typedef struct
{
  gpio_num_t SCK_pin;
  gpio_num_t MISO_pin;
  gpio_num_t MOSI_pin;
  gpio_num_t CS_pin; // chip slect
  gpio_num_t INT_pin; // chân ngắt
} SPI_config;
esp_err_t SPI_init_bus(SPI_config *config_pin, uint8_t max_transfer);
esp_err_t SPI_add_device(gpio_num_t _CS, SPIsetting *cfg, spi_device_handle_t *spi_handle);
/*End SPI CLASS*/
#pragma endregion SPICLASS

/* MAX Class*/
#pragma region MAX30003

#define WREG 0x00
#define RREG 0x01

#define STATUS 0x01
#define EN_INT 0x02
#define EN_INT2 0x03
#define MNGR_INT 0x04
#define MNGR_DYN 0x05
#define SW_RST 0x08
#define SYNCH 0x09
#define FIFO_RST 0x0A
#define INFO 0x0F
#define CNFG_GEN 0x10
#define CNFG_CAL 0x12
#define CNFG_EMUX 0x14
#define CNFG_ECG 0x15
#define CNFG_RTOR1 0x1D
#define CNFG_RTOR2 0x1E
#define ECG_FIFO_BURST 0x20
#define ECG_FIFO 0x21
#define RTOR 0x25

#define CLK_PIN 6
#define RTOR_INTR_MASK 0x04
#define FILTER_WINDOW 5

#define DCLOFF 0x10

typedef enum
{
  SAMPLINGRATE_128 = 128,
  SAMPLINGRATE_256 = 256,
  SAMPLINGRATE_512 = 512
} sampRate;
typedef struct {
  unsigned int RR, heartRate;
}Max30003_Info;

typedef struct MAX30003_context_t *MAX30003_handle_t;
esp_err_t Max30003_init(MAX30003_handle_t *out_handle, SPI_config *config_pin);
esp_err_t max30003RegWrite(MAX30003_handle_t ctx, uint8_t WRITE_ADDRESS, uint32_t data);
esp_err_t max30003RegRead(MAX30003_handle_t ctx, uint8_t Reg_address, uint8_t *buff);

void max30003Begin(MAX30003_handle_t ctx);
void max30003SwReset(MAX30003_handle_t ctx);
void max30003Synch(MAX30003_handle_t ctx);


bool max30003ReadInfo(MAX30003_handle_t ctx);
signed long MAX30003_getEcgSamples(MAX30003_handle_t ctx);
Max30003_Info MAX30003_getHRandRR(MAX30003_handle_t ctx);
void max30003_attach_interrupt(MAX30003_handle_t ctx, gpio_isr_t isr_handler );
void Max30003_ISRgive(MAX30003_handle_t handle, BaseType_t *xHigherPriorityTaskWoken);
#pragma endregion MAX30003

#endif