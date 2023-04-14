################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API_sht31/src/API_sht31.c \
../Drivers/API_sht31/src/port.c 

OBJS += \
./Drivers/API_sht31/src/API_sht31.o \
./Drivers/API_sht31/src/port.o 

C_DEPS += \
./Drivers/API_sht31/src/API_sht31.d \
./Drivers/API_sht31/src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API_sht31/src/%.o Drivers/API_sht31/src/%.su: ../Drivers/API_sht31/src/%.c Drivers/API_sht31/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G031xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/leomu/OneDrive/Escritorio/CESE/PCSE/ProyectoFinal/PCSE_FinalProject/SHT31_read/Drivers/API_sht31" -I"C:/Users/leomu/OneDrive/Escritorio/CESE/PCSE/ProyectoFinal/PCSE_FinalProject/SHT31_read/Drivers/API_sht31/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-API_sht31-2f-src

clean-Drivers-2f-API_sht31-2f-src:
	-$(RM) ./Drivers/API_sht31/src/API_sht31.d ./Drivers/API_sht31/src/API_sht31.o ./Drivers/API_sht31/src/API_sht31.su ./Drivers/API_sht31/src/port.d ./Drivers/API_sht31/src/port.o ./Drivers/API_sht31/src/port.su

.PHONY: clean-Drivers-2f-API_sht31-2f-src

