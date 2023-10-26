################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HLEDMRX/HLEDMRX_prog.c 

OBJS += \
./HAL/HLEDMRX/HLEDMRX_prog.o 

C_DEPS += \
./HAL/HLEDMRX/HLEDMRX_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HLEDMRX/HLEDMRX_prog.o: ../HAL/HLEDMRX/HLEDMRX_prog.c HAL/HLEDMRX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MDMA" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MTIM1" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MSYSTICK" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MADC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MSPI" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/LIB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MUSART" -I../Inc -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/APP" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HBUZZ" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HKEYPAD" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLCD" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLED" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HLEDMRX" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HPB" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/HAL/HSSD/V1" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MAFIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MEXTI" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MGPIO" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MNVIC" -I"D:/NTI-Embedded System/ARM Interfacing/NTI-STM32F103x/STM32F103C8-Drives/MCAL/MRCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/HLEDMRX/HLEDMRX_prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

