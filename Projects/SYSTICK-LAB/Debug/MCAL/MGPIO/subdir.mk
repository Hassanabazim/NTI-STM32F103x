################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MGPIO/MGPIO_prog.c 

OBJS += \
./MCAL/MGPIO/MGPIO_prog.o 

C_DEPS += \
./MCAL/MGPIO/MGPIO_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MGPIO/MGPIO_prog.o: ../MCAL/MGPIO/MGPIO_prog.c MCAL/MGPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/SYSTICK-LAB/LIB" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/SYSTICK-LAB/HAL/HLED" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/SYSTICK-LAB/MCAL/MGPIO" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/SYSTICK-LAB/MCAL/MRCC" -I"C:/Users/Hassa/STM32CubeIDE/workspace_1.6.1/SYSTICK-LAB/MCAL/MSTICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/MGPIO/MGPIO_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

