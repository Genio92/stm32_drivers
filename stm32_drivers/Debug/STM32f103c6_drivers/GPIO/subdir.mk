################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.c 

OBJS += \
./STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.o 

C_DEPS += \
./STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c6_drivers/GPIO/%.o STM32f103c6_drivers/GPIO/%.su: ../STM32f103c6_drivers/GPIO/%.c STM32f103c6_drivers/GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/20100/Documents/Emmbedded system driver/stm32_drivers/HAL/includes" -I"C:/Users/20100/Documents/Emmbedded system driver/stm32_drivers/STM32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32f103c6_drivers-2f-GPIO

clean-STM32f103c6_drivers-2f-GPIO:
	-$(RM) ./STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.d ./STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.o ./STM32f103c6_drivers/GPIO/stm32f103x8_gpio_driver.su

.PHONY: clean-STM32f103c6_drivers-2f-GPIO

