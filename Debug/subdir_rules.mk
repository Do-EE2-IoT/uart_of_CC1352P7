################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Texas_programming/CODE/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mlittle-endian -mthumb -Oz -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang" -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang/Debug" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/source" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/kernel/tirtos7/packages" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/source/ti/posix/ticlang" -DDeviceFamily_CC13X2X7 -gdwarf-3 -march=armv7e-m -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-917629055: ../uart2callback.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1_16_2/sysconfig_cli.bat" -s "C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/.metadata/product.json" --script "D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang/uart2callback.syscfg" -o "syscfg" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_devices_config.c: build-917629055 ../uart2callback.syscfg
syscfg/ti_drivers_config.c: build-917629055
syscfg/ti_drivers_config.h: build-917629055
syscfg/ti_utils_build_linker.cmd.genlibs: build-917629055
syscfg/syscfg_c.rov.xs: build-917629055
syscfg/ti_sysbios_config.h: build-917629055
syscfg/ti_sysbios_config.c: build-917629055
syscfg/: build-917629055

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Texas_programming/CODE/ccs/tools/compiler/ti-cgt-armllvm_2.1.3.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mlittle-endian -mthumb -Oz -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang" -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang/Debug" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/source" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/kernel/tirtos7/packages" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_10_01_24/source/ti/posix/ticlang" -DDeviceFamily_CC13X2X7 -gdwarf-3 -march=armv7e-m -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/TEXAS implement/uart2callback_LP_CC1352P7_1_tirtos7_ticlang/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


