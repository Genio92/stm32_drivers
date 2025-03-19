/*
 * keypad.h
 *
 *  Created on: Mar 19, 2025
 *      Author: Abdelrahman Mahmoud Hussein
 *      Mastering Embedded System Online Diploma
 */

#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_
#include <STM32F103x8.h>
#include <stm32f103x8_gpio_driver.h>

#define KEYPAD_R0_GPIO_PORT GPIOB
#define KEYPAD_R1_GPIO_PORT GPIOB
#define KEYPAD_R2_GPIO_PORT GPIOB
#define KEYPAD_R3_GPIO_PORT GPIOB

#define KEYPAD_C0_GPIO_PORT GPIOB
#define KEYPAD_C1_GPIO_PORT GPIOB
#define KEYPAD_C2_GPIO_PORT GPIOB
#define KEYPAD_C3_GPIO_PORT GPIOB



#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_2
#define R3 GPIO_PIN_3
#define C0 GPIO_PIN_4
#define C1 GPIO_PIN_5
#define C2 GPIO_PIN_6
#define C3 GPIO_PIN_7



void Keypad_init();
char Keypad_getkey();


#endif /* INCLUDES_KEYPAD_H_ */
