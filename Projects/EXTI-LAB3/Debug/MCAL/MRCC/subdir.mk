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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/HAL/HLED" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MSTICK" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/HAL/HPB" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/LIB" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MEXTI" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MAFIO" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MGPIO" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MNVIC" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB3/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MRCC/MRCC_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

