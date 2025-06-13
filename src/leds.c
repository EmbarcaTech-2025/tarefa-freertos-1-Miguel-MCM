#include "leds.h"
#include "pico/stdlib.h"

void setup_leds() {
  // Configura os pinos dos LEDs como saída
  gpio_init(LED_R);
  gpio_set_dir(LED_R, GPIO_OUT);
  gpio_init(LED_G);
  gpio_set_dir(LED_G, GPIO_OUT);
  gpio_init(LED_B);
  gpio_set_dir(LED_B, GPIO_OUT);
}

void led_on(Led led) {
  gpio_put(led, true);
}

void led_off(Led led) {
  gpio_put(led, false);
}

