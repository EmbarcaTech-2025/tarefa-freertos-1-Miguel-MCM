#ifndef LEDS_H
#define LEDS_H

typedef enum Led {
  LED_R = 13, // Red LED
  LED_G = 11, // Green LED
  LED_B = 12  // Blue LED
} Led;

void setup_leds();
void led_on(Led led);
void led_off(Led led);

#endif