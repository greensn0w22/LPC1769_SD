################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SPItest.axf

dependents:
	-cd C:/Users/Julien/Desktop/LPC1769_SD/workplace/SD_Card/Debug && $(MAKE) all

# Tool invocations
SPItest.axf: $(OBJS) $(USER_OBJS) C:/Users/Julien/Desktop/LPC1769_SD/workplace/SD_Card/Debug/libSD_Card.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Julien\Desktop\LPC1769_SD\workplace\SD_Card\Debug" -L"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_board_nxp_lpcxpresso_1769\Debug" -L"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_chip_175x_6x\Debug" -Xlinker -Map="SPItest.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "SPItest_Debug.ld" -o "SPItest.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) SPItest.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "SPItest.axf"; # arm-none-eabi-objcopy -v -O binary "SPItest.axf" "SPItest.bin" ; # checksum -p LPC1769 -d "SPItest.bin";
	-@echo ' '

.PHONY: all clean dependents post-build
C:/Users/Julien/Desktop/LPC1769_SD/workplace/SD_Card/Debug/libSD_Card.a:

-include ../makefile.targets
