################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Custom/GPIOHandler.c \
../Core/Src/Custom/SPIHandler.c \
../Core/Src/Custom/SystemClockConfig.c \
../Core/Src/Custom/doorCam_manager.c \
../Core/Src/Custom/proxSensHandler.c 

OBJS += \
./Core/Src/Custom/GPIOHandler.o \
./Core/Src/Custom/SPIHandler.o \
./Core/Src/Custom/SystemClockConfig.o \
./Core/Src/Custom/doorCam_manager.o \
./Core/Src/Custom/proxSensHandler.o 

C_DEPS += \
./Core/Src/Custom/GPIOHandler.d \
./Core/Src/Custom/SPIHandler.d \
./Core/Src/Custom/SystemClockConfig.d \
./Core/Src/Custom/doorCam_manager.d \
./Core/Src/Custom/proxSensHandler.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Custom/%.o Core/Src/Custom/%.su Core/Src/Custom/%.cyclo: ../Core/Src/Custom/%.c Core/Src/Custom/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Custom

clean-Core-2f-Src-2f-Custom:
	-$(RM) ./Core/Src/Custom/GPIOHandler.cyclo ./Core/Src/Custom/GPIOHandler.d ./Core/Src/Custom/GPIOHandler.o ./Core/Src/Custom/GPIOHandler.su ./Core/Src/Custom/SPIHandler.cyclo ./Core/Src/Custom/SPIHandler.d ./Core/Src/Custom/SPIHandler.o ./Core/Src/Custom/SPIHandler.su ./Core/Src/Custom/SystemClockConfig.cyclo ./Core/Src/Custom/SystemClockConfig.d ./Core/Src/Custom/SystemClockConfig.o ./Core/Src/Custom/SystemClockConfig.su ./Core/Src/Custom/doorCam_manager.cyclo ./Core/Src/Custom/doorCam_manager.d ./Core/Src/Custom/doorCam_manager.o ./Core/Src/Custom/doorCam_manager.su ./Core/Src/Custom/proxSensHandler.cyclo ./Core/Src/Custom/proxSensHandler.d ./Core/Src/Custom/proxSensHandler.o ./Core/Src/Custom/proxSensHandler.su

.PHONY: clean-Core-2f-Src-2f-Custom

