################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SPItest.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/sysinit.c 

OBJS += \
./src/SPItest.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/sysinit.o 

C_DEPS += \
./src/SPItest.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\SPItest\inc" -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_board_nxp_lpcxpresso_1769\inc" -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_chip_175x_6x\inc" -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\SD_Card\src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


