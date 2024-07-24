################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/car/car2.0/B车/B车/4.Demo/Libraries/Device/Core/core_riscv.c 

OBJS += \
./CH32V30x/Core/core_riscv.o 

C_DEPS += \
./CH32V30x/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
CH32V30x/Core/core_riscv.o: D:/car/car2.0/B车/B车/4.Demo/Libraries/Device/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"D:\car\car2.0\B车\B车\4.Demo\testB\CODE" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_libraries\board" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\src" -I"D:\car\car2.0\B车\B车\4.Demo\testB\USER\inc" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\hefei_peripheral" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\Core" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\CH32V30x_Lib" -I"D:\car\car2.0\B车\B车\4.Demo\Libraries\Device\CH32V30x_p\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

