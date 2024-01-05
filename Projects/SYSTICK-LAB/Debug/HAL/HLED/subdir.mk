################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HLED/HLED_prog.c 

OBJS += \
./HAL/HLED/HLED_prog.o 

C_DEPS += \
./HAL/HLED/HLED_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HLED/HLED_prog.o: ../HAL/HLED/HLED_prog.c HAL/HLED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/SYSTICK-LAB/LIB" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/SYSTICK-LAB/HAL/HLED" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/SYSTICK-LAB/MCAL/MGPIO" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/SYSTICK-LAB/MCAL/MRCC" -I"D:/Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/SYSTICK-LAB/MCAL/MSTICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/HLED/HLED_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

