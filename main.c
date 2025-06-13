#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/i2c.h"

#include "leds.h"
#include "buzzer.h"
#include "buttons.h"

TaskHandle_t led_task_handle;
TaskHandle_t buzzer_task_handle;

void led_task() {
  while (true) {
    led_on(LED_R);
    vTaskDelay(pdMS_TO_TICKS(500));
    led_off(LED_R);
    
    led_on(LED_G);
    vTaskDelay(pdMS_TO_TICKS(500));
    led_off(LED_G);
    
    led_on(LED_B);
    vTaskDelay(pdMS_TO_TICKS(500));
    led_off(LED_B);
  }
}

void buzzer_task() {
  while (true) {
    buzzer_on();
    vTaskDelay(pdMS_TO_TICKS(300));
    buzzer_off();
    vTaskDelay(pdMS_TO_TICKS(700));
  }
}

void buttons_A_task() {
  bool state = false;
  while (true) {
    if (get_button_pressed(BUTTON_A)) {
      if (!state) {
        vTaskSuspend(led_task_handle);
        state = true;
      }
    } else {
      if (state) {
        vTaskResume(led_task_handle);
        state = false;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_TIME));
  }
}

void buttons_B_task() {
  bool state = false;
  while (true) {
    if (get_button_pressed(BUTTON_B)) {
      if (!state) {
        vTaskSuspend(buzzer_task_handle);
        buzzer_off();
        state = true;
      }
    } else {
      if (state) {
        vTaskResume(buzzer_task_handle);
        state = false;
      }
    }
    vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_TIME));
  }
}

int main() {
  stdio_init_all();
  setup_leds();
  setup_buzzer();
  setup_buttons();

  xTaskCreate(led_task, "LED_Task", 256, NULL, 1, &led_task_handle);
  xTaskCreate(buzzer_task, "Buzzer_Task", 256, NULL, 1, &buzzer_task_handle);
  
  xTaskCreate(buttons_A_task, "Buttons_A_Task", 256, NULL, 1, NULL);
  xTaskCreate(buttons_B_task, "Buttons_B_Task", 256, NULL, 1, NULL);

  vTaskStartScheduler();

  while(1){};
}