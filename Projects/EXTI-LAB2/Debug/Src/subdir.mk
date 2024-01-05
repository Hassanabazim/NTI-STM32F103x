################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/HAL/HLED" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/HAL/HPB" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/LIB" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/MCAL/EXTINT" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/MCAL/MAFIO" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/MCAL/MGPIO" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/MCAL/MNVIC" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI-LAB2/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

