################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/SEGGER/Recorder/segger_uart.c 

OBJS += \
./Common/ThirdParty/SEGGER/Recorder/segger_uart.o 

C_DEPS += \
./Common/ThirdParty/SEGGER/Recorder/segger_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ThirdParty/SEGGER/Recorder/segger_uart.o: D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/SEGGER/Recorder/segger_uart.c Common/ThirdParty/SEGGER/Recorder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/FreeRTOS/include" -I"D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/SEGGER/Config" -I"D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/SEGGER/OS" -I"D:/Workspace_RTOS/RTOS_workspace/Common/ThirdParty/SEGGER/SEGGER" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-ThirdParty-2f-SEGGER-2f-Recorder

clean-Common-2f-ThirdParty-2f-SEGGER-2f-Recorder:
	-$(RM) ./Common/ThirdParty/SEGGER/Recorder/segger_uart.cyclo ./Common/ThirdParty/SEGGER/Recorder/segger_uart.d ./Common/ThirdParty/SEGGER/Recorder/segger_uart.o ./Common/ThirdParty/SEGGER/Recorder/segger_uart.su

.PHONY: clean-Common-2f-ThirdParty-2f-SEGGER-2f-Recorder

