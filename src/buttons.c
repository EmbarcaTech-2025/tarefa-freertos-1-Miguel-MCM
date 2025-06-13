#include "buttons.h"

void setup_buttons() {
    // Configura os pinos dos botões como entrada
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A); // Ativa o pull-up interno

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B); // Ativa o pull-up interno
}

bool get_button_pressed(Button button) {
    return !gpio_get(button);
}