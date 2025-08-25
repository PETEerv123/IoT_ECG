/* SPI Slave example, sender (uses SPI master driver)

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "esp_timer.h"
#include "Max30003.h"

#define SO 5
#define SI 7
#define SCK 6
#define INT 8
#define CS_PIN_MAX30003 10 // Chân CS của MAX30003

MAX30003_handle_t MAX30003_handle;
// static void IRAM_ATTR max30003_isr_handler(void *arg)
// {
//     BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//     Max30003_ISRgive(MAX30003_handle, &xHigherPriorityTaskWoken);
//     portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // chuyển đổi ngữ cảnh tránh bị lỗi
// }
void app_main(void)
{
    static SPI_config _config = {
        .CS_pin = CS_PIN_MAX30003,
        .MISO_pin = SO,
        .MOSI_pin = SI,
        .SCK_pin = SCK,
        .INT_pin = -1 // ngắt nếu không sài ngắt thì -1
    };

    if (Max30003_init(&MAX30003_handle, &_config) == ESP_OK)
    {
        printf("MAX30003 init success!\n");
    }
    max30003ReadInfo(MAX30003_handle);
    max30003Begin(MAX30003_handle);

    // max30003_attach_interrupt(MAX30003_handle, max30003_isr_handler ) // sử dung ngắt 
    while (1)
    {
        // printf("%ld\n",MAX30003_getEcgSamples(MAX30003_handle));
        Max30003_Info sensor = MAX30003_getHRandRR(MAX30003_handle);
        printf("Heart Beat:%d\n", sensor.heartRate);
        printf("R to R:%d\n", sensor.RR);
        vTaskDelay(21 / portTICK_PERIOD_MS);
    }
}