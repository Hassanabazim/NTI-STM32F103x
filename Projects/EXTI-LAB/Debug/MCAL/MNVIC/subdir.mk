################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MNVIC/MNVIC_prog.c 

OBJS += \
./MCAL/MNVIC/MNVIC_prog.o 

C_DEPS += \
./MCAL/MNVIC/MNVIC_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MNVIC/MNVIC_prog.o: ../MCAL/MNVIC/MNVIC_prog.c MCAL/MNVIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/HAL/HLED" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/LIB" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/HAL/HPB" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/EXTINT" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MGPIO" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MNVIC" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MNVIC/MNVIC_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

