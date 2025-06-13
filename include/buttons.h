#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"

#define DEBOUNCE_TIME 100

typedef enum Button {
  BUTTON_A = 5,
  BUTTON_B = 6,
  BUTTON_NONE = -1
} Button;

void setup_buttons();
bool get_button_pressed(Button button);

#endif // BUTTONS_H