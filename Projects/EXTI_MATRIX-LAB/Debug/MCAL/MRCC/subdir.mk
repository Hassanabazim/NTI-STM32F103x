################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MRCC/MRCC_prog.c 

OBJS += \
./MCAL/MRCC/MRCC_prog.o 

C_DEPS += \
./MCAL/MRCC/MRCC_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MRCC/MRCC_prog.o: ../MCAL/MRCC/MRCC_prog.c MCAL/MRCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/HAL/HLEDMRX" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/HAL/HPB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/LIB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MAFIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MEXTI" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MGPIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MNVIC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MRCC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/Projects/EXTI_MATRIX-LAB/MCAL/MSTICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MRCC/MRCC_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

