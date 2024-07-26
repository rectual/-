################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_Double_DC_Motor.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_HC_SR04.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_IPS114.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_MT9V03X.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_TFT180.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_WS2812b.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_Wireless_uart.c \
D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/dmx_tof400c.c 

OBJS += \
./hefei_peripheral/HF_Double_DC_Motor.o \
./hefei_peripheral/HF_HC_SR04.o \
./hefei_peripheral/HF_IPS114.o \
./hefei_peripheral/HF_MT9V03X.o \
./hefei_peripheral/HF_TFT180.o \
./hefei_peripheral/HF_WS2812b.o \
./hefei_peripheral/HF_Wireless_uart.o \
./hefei_peripheral/dmx_tof400c.o 

C_DEPS += \
./hefei_peripheral/HF_Double_DC_Motor.d \
./hefei_peripheral/HF_HC_SR04.d \
./hefei_peripheral/HF_IPS114.d \
./hefei_peripheral/HF_MT9V03X.d \
./hefei_peripheral/HF_TFT180.d \
./hefei_peripheral/HF_WS2812b.d \
./hefei_peripheral/HF_Wireless_uart.d \
./hefei_peripheral/dmx_tof400c.d 


# Each subdirectory must supply rules for building sources it contributes
hefei_peripheral/HF_Double_DC_Motor.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_Double_DC_Motor.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_HC_SR04.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_HC_SR04.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_IPS114.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_IPS114.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_MT9V03X.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_MT9V03X.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_TFT180.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_TFT180.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_WS2812b.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_WS2812b.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/HF_Wireless_uart.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/HF_Wireless_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
hefei_peripheral/dmx_tof400c.o: D:/智能车代码/A车/4.Demo/Libraries/hefei_peripheral/dmx_tof400c.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

