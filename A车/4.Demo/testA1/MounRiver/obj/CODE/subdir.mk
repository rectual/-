################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/Bend.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/CrossRound.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/PLC.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/Round.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/binary.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/board_led.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_adc.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_init.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_keys.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_ligth.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_motion.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_reed.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_uart.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_value_process.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/center_line.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/junction.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/pid.c \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/show.c 

OBJS += \
./CODE/Bend.o \
./CODE/CrossRound.o \
./CODE/PLC.o \
./CODE/Round.o \
./CODE/binary.o \
./CODE/board_led.o \
./CODE/car_adc.o \
./CODE/car_init.o \
./CODE/car_keys.o \
./CODE/car_ligth.o \
./CODE/car_motion.o \
./CODE/car_reed.o \
./CODE/car_uart.o \
./CODE/car_value_process.o \
./CODE/center_line.o \
./CODE/junction.o \
./CODE/pid.o \
./CODE/show.o 

C_DEPS += \
./CODE/Bend.d \
./CODE/CrossRound.d \
./CODE/PLC.d \
./CODE/Round.d \
./CODE/binary.d \
./CODE/board_led.d \
./CODE/car_adc.d \
./CODE/car_init.d \
./CODE/car_keys.d \
./CODE/car_ligth.d \
./CODE/car_motion.d \
./CODE/car_reed.d \
./CODE/car_uart.d \
./CODE/car_value_process.d \
./CODE/center_line.d \
./CODE/junction.d \
./CODE/pid.d \
./CODE/show.d 


# Each subdirectory must supply rules for building sources it contributes
CODE/Bend.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/Bend.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/CrossRound.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/CrossRound.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/PLC.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/PLC.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/Round.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/Round.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/binary.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/binary.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/board_led.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/board_led.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_adc.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_init.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_init.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_keys.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_keys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_ligth.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_ligth.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_motion.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_motion.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_reed.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_reed.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_uart.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_value_process.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/car_value_process.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/center_line.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/center_line.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/junction.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/junction.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/pid.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/pid.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/show.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/testA1/CODE/show.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

