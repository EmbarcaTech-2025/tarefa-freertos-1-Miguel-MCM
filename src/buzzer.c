#include "buzzer.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

void setup_buzzer() {
  gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

  pwm_config config = pwm_get_default_config();
  pwm_config_set_clkdiv(&config, BUZZER_CLK_DIV);
  pwm_init(slice_num, &config, true);

  pwm_set_gpio_level(BUZZER_PIN, 0);
}

void buzzer_on() {
    pwm_set_gpio_level(BUZZER_PIN, 0x7fff);
}

void buzzer_off() {
    pwm_set_gpio_level(BUZZER_PIN, 0);
}