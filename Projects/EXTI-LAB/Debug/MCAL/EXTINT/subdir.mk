################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTINT/EXTINT_prog.c 

OBJS += \
./MCAL/EXTINT/EXTINT_prog.o 

C_DEPS += \
./MCAL/EXTINT/EXTINT_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTINT/EXTINT_prog.o: ../MCAL/EXTINT/EXTINT_prog.c MCAL/EXTINT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/HAL/HLED" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/LIB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/HAL/HPB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/EXTINT" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MGPIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MNVIC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/EXTINT/EXTINT_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

