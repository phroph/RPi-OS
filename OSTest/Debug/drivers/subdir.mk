################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/gpio.c 

OBJS += \
./drivers/gpio.o 

C_DEPS += \
./drivers/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Users\Phillip\Documents\DS-5 Workspace\OSTest\drivers" -I"C:\Users\Phillip\Documents\DS-5 Workspace\OSTest" -I"C:\glibc\include" -O0 -g -Wall -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


