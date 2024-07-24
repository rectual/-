################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/Bend.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/CrossRound.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/PLC.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/Round.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/binary.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/board_led.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_adc.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_init.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_keys.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_ligth.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_motion.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_reed.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_uart.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_value_process.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/center_line.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/junction.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/pid.c \
D:/car/car2.0/B车/B车/4.Demo/testB/CODE/show.c 

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
CODE/Bend.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/Bend.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/CrossRound.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/CrossRound.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/PLC.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/PLC.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/Round.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/Round.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/binary.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/binary.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/board_led.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/board_led.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_adc.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_init.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_init.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_keys.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_keys.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_ligth.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_ligth.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_motion.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_motion.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_reed.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_reed.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_uart.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/car_value_process.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/car_value_process.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/center_line.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/center_line.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/junction.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/junction.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/pid.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/pid.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
CODE/show.o: D:/car/car2.0/B车/B车/4.Demo/testB/CODE/show.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

