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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/HAL/HLED" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/LIB" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/HAL/HPB" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/MCAL/EXTINT" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/MCAL/MGPIO" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/MCAL/MNVIC" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/EXTI-LAB/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

