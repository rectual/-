################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/car/newcar/A车/4.Demo/Libraries/hefei_libraries/board/board.c 

OBJS += \
./hefei_libraries/board/board.o 

C_DEPS += \
./hefei_libraries/board/board.d 


# Each subdirectory must supply rules for building sources it contributes
hefei_libraries/board/board.o: D:/car/newcar/A车/4.Demo/Libraries/hefei_libraries/board/board.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\newcar\A车\4.Demo\testA\CODE" -I"D:\car\newcar\A车\4.Demo\Libraries\hefei_libraries" -I"D:\car\newcar\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\newcar\A车\4.Demo\testA\USER\src" -I"D:\car\newcar\A车\4.Demo\testA\USER\inc" -I"D:\car\newcar\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\newcar\A车\4.Demo\Libraries\Device\Core" -I"D:\car\newcar\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\newcar\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

