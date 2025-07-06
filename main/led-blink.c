#include <stdio.h>
#include "driver/gpio.h"                            // library to control GPIO pins
#include "freertos/FreeRTOS.h"                      // real-time operating system (RTOS) headers
#include "freertos/task.h"                          // provides task delays

#define led_pin 2                                   // define GPIO pin number as 2 for LED, like saying "const led_pin = 2"

void app_main(void) {
    gpio_reset_pin(led_pin);                        // reset pin to default state
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);  // set GPIO pin as OUTPUT

    while (1) {
        gpio_set_level(led_pin, true);              // LED ON
        vTaskDelay(1000 / portTICK_PERIOD_MS);      // 1000ms delay

        gpio_set_level(led_pin, false);             // LED OFF
        vTaskDelay(1000 / portTICK_PERIOD_MS);      // 1000ms delay
    }
    
    // FUNCTION MUST NEVER RETURN!
}