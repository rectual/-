################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/IDE/A车/A车/A车/基础组摄像头资料（摄像头）资料A/4.Demo/Libraries/Device/Core/core_riscv.c 

OBJS += \
./CH32V30x/Core/core_riscv.o 

C_DEPS += \
./CH32V30x/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
CH32V30x/Core/core_riscv.o: D:/IDE/A车/A车/A车/基础组摄像头资料（摄像头）资料A/4.Demo/Libraries/Device/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\09-Car_CAM_IPS\CODE" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\hefei_libraries" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\hefei_libraries\board" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\09-Car_CAM_IPS\USER\src" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\09-Car_CAM_IPS\USER\inc" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\hefei_peripheral" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\Device\Core" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

