################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/ͼƬ��/����������ͷ���ϣ�����ͷ������V1.3/4.Demo/testA1/USER/src/isr.c \
F:/ͼƬ��/����������ͷ���ϣ�����ͷ������V1.3/4.Demo/testA1/USER/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: F:/ͼƬ��/����������ͷ���ϣ�����ͷ������V1.3/4.Demo/testA1/USER/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\CODE" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\USER\src" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\USER\inc" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\Core" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: F:/ͼƬ��/����������ͷ���ϣ�����ͷ������V1.3/4.Demo/testA1/USER/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\CODE" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\USER\src" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\testA1\USER\inc" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\Core" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\ͼƬ��\����������ͷ���ϣ�����ͷ������V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

