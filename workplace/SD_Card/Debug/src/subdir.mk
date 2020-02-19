################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ff.c \
../src/ffsystem.c \
../src/ffunicode.c \
../src/mmc.c \
../src/spi.c 

OBJS += \
./src/ff.o \
./src/ffsystem.o \
./src/ffunicode.o \
./src/mmc.o \
./src/spi.o 

C_DEPS += \
./src/ff.d \
./src/ffsystem.d \
./src/ffunicode.d \
./src/mmc.d \
./src/spi.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -DCR_INTEGER_PRINTF -DCR_PRINTF_CHAR -D__LPC17XX__ -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\SD_Card\inc" -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_board_nxp_lpcxpresso_1769\inc" -I"C:\Users\Julien\Desktop\LPC1769_SD\workplace\lpc_chip_175x_6x\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


