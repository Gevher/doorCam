################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Machine-made/freertos.c \
../Core/Src/Machine-made/main.c \
../Core/Src/Machine-made/stm32f0xx_hal_msp.c \
../Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.c \
../Core/Src/Machine-made/stm32f0xx_it.c \
../Core/Src/Machine-made/syscalls.c \
../Core/Src/Machine-made/sysmem.c \
../Core/Src/Machine-made/system_stm32f0xx.c 

OBJS += \
./Core/Src/Machine-made/freertos.o \
./Core/Src/Machine-made/main.o \
./Core/Src/Machine-made/stm32f0xx_hal_msp.o \
./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.o \
./Core/Src/Machine-made/stm32f0xx_it.o \
./Core/Src/Machine-made/syscalls.o \
./Core/Src/Machine-made/sysmem.o \
./Core/Src/Machine-made/system_stm32f0xx.o 

C_DEPS += \
./Core/Src/Machine-made/freertos.d \
./Core/Src/Machine-made/main.d \
./Core/Src/Machine-made/stm32f0xx_hal_msp.d \
./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.d \
./Core/Src/Machine-made/stm32f0xx_it.d \
./Core/Src/Machine-made/syscalls.d \
./Core/Src/Machine-made/sysmem.d \
./Core/Src/Machine-made/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Machine-made/%.o Core/Src/Machine-made/%.su Core/Src/Machine-made/%.cyclo: ../Core/Src/Machine-made/%.c Core/Src/Machine-made/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Machine-2d-made

clean-Core-2f-Src-2f-Machine-2d-made:
	-$(RM) ./Core/Src/Machine-made/freertos.cyclo ./Core/Src/Machine-made/freertos.d ./Core/Src/Machine-made/freertos.o ./Core/Src/Machine-made/freertos.su ./Core/Src/Machine-made/main.cyclo ./Core/Src/Machine-made/main.d ./Core/Src/Machine-made/main.o ./Core/Src/Machine-made/main.su ./Core/Src/Machine-made/stm32f0xx_hal_msp.cyclo ./Core/Src/Machine-made/stm32f0xx_hal_msp.d ./Core/Src/Machine-made/stm32f0xx_hal_msp.o ./Core/Src/Machine-made/stm32f0xx_hal_msp.su ./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.cyclo ./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.d ./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.o ./Core/Src/Machine-made/stm32f0xx_hal_timebase_tim.su ./Core/Src/Machine-made/stm32f0xx_it.cyclo ./Core/Src/Machine-made/stm32f0xx_it.d ./Core/Src/Machine-made/stm32f0xx_it.o ./Core/Src/Machine-made/stm32f0xx_it.su ./Core/Src/Machine-made/syscalls.cyclo ./Core/Src/Machine-made/syscalls.d ./Core/Src/Machine-made/syscalls.o ./Core/Src/Machine-made/syscalls.su ./Core/Src/Machine-made/sysmem.cyclo ./Core/Src/Machine-made/sysmem.d ./Core/Src/Machine-made/sysmem.o ./Core/Src/Machine-made/sysmem.su ./Core/Src/Machine-made/system_stm32f0xx.cyclo ./Core/Src/Machine-made/system_stm32f0xx.d ./Core/Src/Machine-made/system_stm32f0xx.o ./Core/Src/Machine-made/system_stm32f0xx.su

.PHONY: clean-Core-2f-Src-2f-Machine-2d-made

