#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PIN 21 
//#define BUZZER_PIN 10 
#define BUZZER_FREQ 880
#define BUZZER_CLK_DIV (SYS_CLK_HZ/(BUZZER_FREQ * 2 * 4096))

void setup_buzzer();
void buzzer_on();
void buzzer_off();

#endif // BUZZER_H