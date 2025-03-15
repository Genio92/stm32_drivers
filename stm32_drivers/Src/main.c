/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <STM32F103x8.h>
#include <stm32f103x8_gpio_driver.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define blue_led_pin GPIO_PIN_1
#define blue_led_GPIO GPIOA

#define green_led_pin GPIO_PIN_2
#define green_led_GPIO GPIOA

#define btn_green_pin GPIO_PIN_1
#define btn_green_GPIO GPIOB

#define btn_blue_pin GPIO_PIN_0
#define btn_blue_GPIO GPIOB




GPIO_PinConfig_t blue_led={blue_led_pin,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_10M};
GPIO_PinConfig_t green_led={green_led_pin,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_10M};

GPIO_PinConfig_t btn_green={btn_green_pin,GPIO_MODE_INPUT_FLO};
GPIO_PinConfig_t btn_blue={btn_blue_pin,GPIO_MODE_INPUT_FLO};


void delay(){

for(int i=0;i<100000;i++);
return;
}


int main(void)
{    RCC_GPIOA_CLK_EN();
	 MCAL_GPIO_Init(blue_led_GPIO, &blue_led);
	 MCAL_GPIO_Init(green_led_GPIO, &green_led);

	 RCC_GPIOB_CLK_EN();
	 MCAL_GPIO_Init(btn_green_GPIO, &btn_green);
	 MCAL_GPIO_Init(btn_blue_GPIO, &btn_blue);

	 /* Loop forever */
	while(1){
      if (MCAL_GPIO_ReadPin(btn_green_GPIO, btn_green_pin)==HIGH){
    	  while(MCAL_GPIO_ReadPin(btn_green_GPIO, btn_green_pin)==HIGH);
    	  MCAL_GPIO_TogglePin(green_led_GPIO, green_led_pin);
      }
      if (MCAL_GPIO_ReadPin(btn_blue_GPIO, btn_blue_pin)==HIGH){
    	  while(MCAL_GPIO_ReadPin(btn_blue_GPIO, btn_blue_pin)==HIGH){
    		  delay();
    		  MCAL_GPIO_TogglePin(blue_led_GPIO, blue_led_pin);
    	  }
      }
	}
	for(;;);
}
