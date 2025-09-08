################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bluetoothInit.c \
../Src/main.c \
../Src/processCommand.c \
../Src/pwmInit.c \
../Src/readCommand.c \
../Src/setDuty.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/bluetoothInit.o \
./Src/main.o \
./Src/processCommand.o \
./Src/pwmInit.o \
./Src/readCommand.o \
./Src/setDuty.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/bluetoothInit.d \
./Src/main.d \
./Src/processCommand.d \
./Src/pwmInit.d \
./Src/readCommand.d \
./Src/setDuty.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F051R8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/bluetoothInit.cyclo ./Src/bluetoothInit.d ./Src/bluetoothInit.o ./Src/bluetoothInit.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/processCommand.cyclo ./Src/processCommand.d ./Src/processCommand.o ./Src/processCommand.su ./Src/pwmInit.cyclo ./Src/pwmInit.d ./Src/pwmInit.o ./Src/pwmInit.su ./Src/readCommand.cyclo ./Src/readCommand.d ./Src/readCommand.o ./Src/readCommand.su ./Src/setDuty.cyclo ./Src/setDuty.d ./Src/setDuty.o ./Src/setDuty.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

