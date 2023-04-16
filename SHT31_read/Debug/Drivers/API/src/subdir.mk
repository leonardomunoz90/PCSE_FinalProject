################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_FSM.c \
../Drivers/API/src/API_delay.c \
../Drivers/API/src/API_sht31.c \
../Drivers/API/src/API_uart.c \
../Drivers/API/src/port.c 

OBJS += \
./Drivers/API/src/API_FSM.o \
./Drivers/API/src/API_delay.o \
./Drivers/API/src/API_sht31.o \
./Drivers/API/src/API_uart.o \
./Drivers/API/src/port.o 

C_DEPS += \
./Drivers/API/src/API_FSM.d \
./Drivers/API/src/API_delay.d \
./Drivers/API/src/API_sht31.d \
./Drivers/API/src/API_uart.d \
./Drivers/API/src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o Drivers/API/src/%.su: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G031xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/leomu/OneDrive/Escritorio/CESE/PCSE/ProyectoFinal/PCSE_FinalProject/SHT31_read/Drivers/API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_FSM.d ./Drivers/API/src/API_FSM.o ./Drivers/API/src/API_FSM.su ./Drivers/API/src/API_delay.d ./Drivers/API/src/API_delay.o ./Drivers/API/src/API_delay.su ./Drivers/API/src/API_sht31.d ./Drivers/API/src/API_sht31.o ./Drivers/API/src/API_sht31.su ./Drivers/API/src/API_uart.d ./Drivers/API/src/API_uart.o ./Drivers/API/src/API_uart.su ./Drivers/API/src/port.d ./Drivers/API/src/port.o ./Drivers/API/src/port.su

.PHONY: clean-Drivers-2f-API-2f-src

