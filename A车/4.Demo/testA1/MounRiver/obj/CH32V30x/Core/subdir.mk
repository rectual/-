################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/Device/Core/core_riscv.c 

OBJS += \
./CH32V30x/Core/core_riscv.o 

C_DEPS += \
./CH32V30x/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
CH32V30x/Core/core_riscv.o: F:/图片库/基础组摄像头资料（摄像头）资料V1.3/4.Demo/Libraries/Device/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\CODE" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_libraries\board" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\src" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\testA1\USER\inc" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\hefei_peripheral" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\Core" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"F:\图片库\基础组摄像头资料（摄像头）资料V1.3\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

