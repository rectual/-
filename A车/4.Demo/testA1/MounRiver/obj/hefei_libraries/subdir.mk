################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/common.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/delay.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_adc.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_common_font.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_dma.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_dvp.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_encoder.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_exti.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_flash.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_gpio.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_i2c_hardware.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_i2c_software.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_nvic.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_pit.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_pwm.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_spi.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_tim.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_uart.c 

OBJS += \
./hefei_libraries/common.o \
./hefei_libraries/delay.o \
./hefei_libraries/hf_adc.o \
./hefei_libraries/hf_common_font.o \
./hefei_libraries/hf_dma.o \
./hefei_libraries/hf_dvp.o \
./hefei_libraries/hf_encoder.o \
./hefei_libraries/hf_exti.o \
./hefei_libraries/hf_flash.o \
./hefei_libraries/hf_gpio.o \
./hefei_libraries/hf_i2c_hardware.o \
./hefei_libraries/hf_i2c_software.o \
./hefei_libraries/hf_nvic.o \
./hefei_libraries/hf_pit.o \
./hefei_libraries/hf_pwm.o \
./hefei_libraries/hf_spi.o \
./hefei_libraries/hf_tim.o \
./hefei_libraries/hf_uart.o 

C_DEPS += \
./hefei_libraries/common.d \
./hefei_libraries/delay.d \
./hefei_libraries/hf_adc.d \
./hefei_libraries/hf_common_font.d \
./hefei_libraries/hf_dma.d \
./hefei_libraries/hf_dvp.d \
./hefei_libraries/hf_encoder.d \
./hefei_libraries/hf_exti.d \
./hefei_libraries/hf_flash.d \
./hefei_libraries/hf_gpio.d \
./hefei_libraries/hf_i2c_hardware.d \
./hefei_libraries/hf_i2c_software.d \
./hefei_libraries/hf_nvic.d \
./hefei_libraries/hf_pit.d \
./hefei_libraries/hf_pwm.d \
./hefei_libraries/hf_spi.d \
./hefei_libraries/hf_tim.d \
./hefei_libraries/hf_uart.d 


# Each subdirectory must supply rules for building sources it contributes
hefei_libraries/common.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/common.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/delay.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/delay.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_adc.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_common_font.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_dma.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_dvp.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_encoder.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_exti.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_flash.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_gpio.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_i2c_hardware.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_i2c_hardware.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_i2c_software.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_i2c_software.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_nvic.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_nvic.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_pit.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_pit.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_pwm.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_pwm.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_spi.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_tim.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_libraries/hf_uart.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/hefei_libraries/hf_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

