################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include OS/subdir.mk
-include MCAL/UART/Source/subdir.mk
-include MCAL/TIMER0/Source/subdir.mk
-include MCAL/DIO/Source/subdir.mk
-include MCAL/ADC/Source/subdir.mk
-include HAL/TempSens/Source/subdir.mk
-include HAL/LCD/Source/subdir.mk
-include HAL/KPD/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
HelloFreeRTOS.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: HelloFreeRTOS.elf secondary-outputs

# Tool invocations
HelloFreeRTOS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,HelloFreeRTOS.map -mmcu=atmega32 -o "HelloFreeRTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HelloFreeRTOS.lss: HelloFreeRTOS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S HelloFreeRTOS.elf  >"HelloFreeRTOS.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: HelloFreeRTOS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 HelloFreeRTOS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) HelloFreeRTOS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
