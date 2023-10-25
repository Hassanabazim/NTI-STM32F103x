################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/APP_prog.c 

OBJS += \
./APP/APP_prog.o 

C_DEPS += \
./APP/APP_prog.d 


# Each subdirectory must supply rules for building sources it contributes
APP/APP_prog.o: ../APP/APP_prog.c APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MDMA" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MSYSTICK" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MADC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MSPI" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/LIB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MUSART" -I../Inc -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/APP" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HBUZZ" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HKEYPAD" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLCD" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLED" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLEDMRX" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HPB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HSSD/V1" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MAFIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MEXTI" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MGPIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MNVIC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"APP/APP_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

