################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/智能车代码/A车/4.Demo/testA/USER/src/isr.c \
D:/智能车代码/A车/4.Demo/testA/USER/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: D:/智能车代码/A车/4.Demo/testA/USER/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: D:/智能车代码/A车/4.Demo/testA/USER/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\智能车代码\A车\4.Demo\testA\CODE" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_libraries\board" -I"D:\智能车代码\A车\4.Demo\testA\USER\src" -I"D:\智能车代码\A车\4.Demo\testA\USER\inc" -I"D:\智能车代码\A车\4.Demo\Libraries\hefei_peripheral" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\Core" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\智能车代码\A车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

