################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/���ܳ�����/A��/4.Demo/testA/USER/src/isr.c \
D:/���ܳ�����/A��/4.Demo/testA/USER/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: D:/���ܳ�����/A��/4.Demo/testA/USER/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\���ܳ�����\A��\4.Demo\testA\CODE" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_libraries" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_libraries\board" -I"D:\���ܳ�����\A��\4.Demo\testA\USER\src" -I"D:\���ܳ�����\A��\4.Demo\testA\USER\inc" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_peripheral" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\Core" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: D:/���ܳ�����/A��/4.Demo/testA/USER/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\���ܳ�����\A��\4.Demo\testA\CODE" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_libraries" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_libraries\board" -I"D:\���ܳ�����\A��\4.Demo\testA\USER\src" -I"D:\���ܳ�����\A��\4.Demo\testA\USER\inc" -I"D:\���ܳ�����\A��\4.Demo\Libraries\hefei_peripheral" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\Core" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\���ܳ�����\A��\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

