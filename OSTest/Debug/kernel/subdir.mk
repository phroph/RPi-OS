################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kernel/main.c 

OBJS += \
./kernel/main.o 

C_DEPS += \
./kernel/main.d 


# Each subdirectory must supply rules for building sources it contributes
kernel/%.o: ../kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Users\Phillip\Documents\DS-5 Workspace\OSTest\drivers" -I"C:\Users\Phillip\Documents\DS-5 Workspace\OSTest" -I"C:\glibc\include" -O0 -g -Wall -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


