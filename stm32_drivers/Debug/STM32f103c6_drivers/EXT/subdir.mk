################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.c 

OBJS += \
./STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.o 

C_DEPS += \
./STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c6_drivers/EXT/%.o STM32f103c6_drivers/EXT/%.su: ../STM32f103c6_drivers/EXT/%.c STM32f103c6_drivers/EXT/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/20100/Documents/Emmbedded system driver/stm32_drivers/HAL/includes" -I"C:/Users/20100/Documents/Emmbedded system driver/stm32_drivers/STM32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32f103c6_drivers-2f-EXT

clean-STM32f103c6_drivers-2f-EXT:
	-$(RM) ./STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.d ./STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.o ./STM32f103c6_drivers/EXT/stm32f103x8_EXTI_driver.su

.PHONY: clean-STM32f103c6_drivers-2f-EXT

