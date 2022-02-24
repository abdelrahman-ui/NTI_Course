################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/EXTI_prog.c \
../Src/GPIO_program.c \
../Src/NVIC_prog.c \
../Src/RCC_program.c \
../Src/STK_prog.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/EXTI_prog.o \
./Src/GPIO_program.o \
./Src/NVIC_prog.o \
./Src/RCC_program.o \
./Src/STK_prog.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/EXTI_prog.d \
./Src/GPIO_program.d \
./Src/NVIC_prog.d \
./Src/RCC_program.d \
./Src/STK_prog.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/EXTI_prog.d ./Src/EXTI_prog.o ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/NVIC_prog.d ./Src/NVIC_prog.o ./Src/RCC_program.d ./Src/RCC_program.o ./Src/STK_prog.d ./Src/STK_prog.o ./Src/main.d ./Src/main.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o

.PHONY: clean-Src

