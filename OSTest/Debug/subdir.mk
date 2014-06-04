################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../_start.s 

OBJS += \
./_start.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.s
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	arm-none-eabi-as -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


