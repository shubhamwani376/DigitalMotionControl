###########################################################################
## Makefile generated for component 'motorkitc2000_with_controller_working'. 
## 
## Makefile     : motorkitc2000_with_controller_working.mk
## Generated on : Mon Jan 23 17:38:48 2023
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/motorkitc2000_with_controller_working.out
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = motorkitc2000_with_controller_working
MAKEFILE                  = motorkitc2000_with_controller_working.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/ONEDRI~2/ONEDRI~1/UCLA/277/DIGITA~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = TI C28x
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS
# TIF28XXXSYSSWDIR

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_C2000_SHARED_DIR              = $(TARGET_PKG_INSTALLDIR)/../../../shared/supportpackages/tic2000
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
F28_HEADERS                      = $(TIF28XXXSYSSWDIR)/~SupportFiles/DSP280x_headers
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_DWO                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).dwo
PRODUCT_ELF                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).elf
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
PRODUCT_DEP                      = $(PRODUCT_NAME).txt
DEPFILE_UPDATE                   = $(TI_C2000_SHARED_DIR)/tools/PostBuildDepedency/win64/DepedencyFileUpdate.ps1
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# DWO Converter: DWO Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS = --abi=coffabi -s -v28 -ml $(ASFLAGS_ADDITIONAL)

CFLAGS = --abi=coffabi --compile_only --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  --large_memory_model --silicon_version=28 --define="LARGE_MODEL" -I"$(F28_HEADERS)" -I"$(F28_HEADERS)/include" -I"$(TI_INCLUDE)" -g

LDFLAGS = --abi=coffabi -z -I$(TI_LIB) --stack_size=$(STACK_SIZE) --warn_sections --heap_size=$(HEAP_SIZE) --reread_libs --rom_model --priority -m"$(PRODUCT_NAME).map"

SHAREDLIB_LDFLAGS = 

CPPFLAGS = -g

CPP_LDFLAGS = 

CPP_SHAREDLIB_LDFLAGS = 

ARFLAGS = -r

OBJCOPYFLAGS_HEX = -i "$<" -o "$@" -order MS -romwidth 16 -q

OBJCOPYFLAGS_DWO = "$<"

DOWNLOAD_FLAGS = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/motorkitc2000_with_controller_working.out
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/motorkitc2000_with_controller_working_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/tic2000/inc -I$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/shared/SUPPOR~1/tic2000/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/shared/SUPPOR~1/tic2000/inc -ID:/ti/C2000W~2/LIBRAR~1/CALIBR~1/hrpwm/f2837xd/include -ID:/ti/C2000W~2/DRIVER~1/f2837xd/DRIVER~1 -ID:/ti/C2000W~2/DRIVER~1/f2837xd/DRIVER~1/inc -ID:/ti/C2000W~2/DEVICE~1/f2837xd/common/include -ID:/ti/C2000W~2/DEVICE~1/f2837xd/headers/include -ID:/ti/C2000W~2/DEVICE~1/f2837xd/common

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DXCP_MAX_CTO_SIZE=32 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DXCP_MAX_DAQ=65535 -DXCP_MIN_DAQ=0 -DXCP_MAX_EVENT_CHANNEL=128 -DXCP_ID_FIELD_TYPE=0 -DXCP_TIMESTAMP_SIZE=4 -DXCP_ADDRESS_GRANULARITY=XCP_ADDRESS_GRANULARITY_WORD -DCODERTARGET_XCP_DAQ_PACKED_MODE -DCODERTARGET_XCP_MAX_CONTIGUOUS_SAMPLES=8
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_EXTMODE_SIMULATION_TIME_IN_TICKS -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DXCP_SET_MTA_SUPPORT -DEXTMODE_XCP_TRIGGER_SUPPORT -DINTERNAL_XCP_MEM_BLOCK_1_SIZE=160 -DINTERNAL_XCP_MEM_BLOCK_1_NUMBER=1 -DINTERNAL_XCP_MEM_BLOCK_2_SIZE=144 -DINTERNAL_XCP_MEM_BLOCK_2_NUMBER=5 -DINTERNAL_XCP_MEM_BLOCK_3_SIZE=64 -DINTERNAL_XCP_MEM_BLOCK_3_NUMBER=5 -DINTERNAL_XCP_MEM_RESERVED_POOLS_TOTAL_SIZE=2662 -DINTERNAL_XCP_MEM_RESERVED_POOLS_NUMBER=6 -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=1000000 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=0 -DXCP_MEM_BLOCK_1_SIZE=64 -DXCP_MEM_BLOCK_1_NUMBER=1 -DXCP_MEM_BLOCK_2_SIZE=48 -DXCP_MEM_BLOCK_2_NUMBER=2 -DXCP_MEM_BLOCK_3_SIZE=64 -DXCP_MEM_BLOCK_3_NUMBER=2 -DXCP_MEM_RESERVED_POOLS_TOTAL_SIZE=1000 -DXCP_MEM_RESERVED_POOLS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=2 -DXCP_MIN_EVENT_NO_RESERVED_POOL=2
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DMW_PIL_SCIFIFOLEN=16 -DF2837X_REG_FORMAT -DMW_F2837XD -DSTACK_SIZE=1024 -DRT -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x1000
DEFINES_STANDARD = -DMODEL=motorkitc2000_with_controller_working -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_csl.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_board.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_pwm.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_qep.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/motorkitc2000_with_controller_working.c $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/motorkitc2000_with_controller_working_data.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common/xcp_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/sysctl.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/c2837xDBoard_Realtime_Support.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/dma.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CpuTimers.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Dma.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Lite.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/tic2000/src/c2000HardwareTimerConfig.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/clb.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/c2837xDSchedulerTimer0.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/rtiostream_serial_c28x_ext_xcp.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/datamodify_xcp.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/tic2000/src/c2000HardwareTimerSupport.c

MAIN_SRC = $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xcp_ext_mode.obj MW_c28xx_csl.obj MW_c28xx_board.obj MW_c28xx_pwm.obj MW_c28xx_qep.obj motorkitc2000_with_controller_working.obj motorkitc2000_with_controller_working_data.obj xcp_ext_common.obj xcp_ext_classic_trigger.obj xcp.obj xcp_standard.obj xcp_daq.obj xcp_calibration.obj xcp_fifo.obj xcp_transport.obj xcp_mem_default.obj xcp_drv_rtiostream.obj xcp_utils.obj xcp_frame_serial.obj xcp_ext_param_default_serial.obj sysctl.obj c2837xDBoard_Realtime_Support.obj MW_c28xGlobalInterrupts.obj dma.obj F2837xD_CpuTimers.obj F2837xD_DefaultISR.obj F2837xD_GlobalVariableDefs.obj F2837xD_PieCtrl.obj F2837xD_PieVect.obj F2837xD_SysCtrl.obj F2837xD_usDelay.obj F2837xD_CodeStartBranch.obj F2837xD_Dma.obj F2837xD_Adc.obj F2837xD_Gpio.obj F2837xD_Ipc_Driver_Lite.obj c2000HardwareTimerConfig.obj MW_c28xGPIO.obj clb.obj c2837xDSchedulerTimer0.obj rtiostream_serial_c28x_ext_xcp.obj datamodify_xcp.obj c2000HardwareTimerSupport.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = D:/ti/C2000Ware_4_00_00_00/libraries/math/IQmath/c28/lib/IQmath_fpu32.lib C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/c2837xDPeripherals.cmd C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/tic2000/src/c28377D.cmd

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x1000
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x1000

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x1000

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CPPFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF28379D -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_PROG_START=0x8000 -DCPU_RAMLS_PROG_LENGTH=0x1800 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x9800 -DCLA_RAMLS_DATA_LENGTH=0x1000
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x1000

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -l"rts2800_fpu32.lib" --define F28379D --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_PROG_START=0x8000 --define CPU_RAMLS_PROG_LENGTH=0x1800 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x9800 --define CLA_RAMLS_DATA_LENGTH=0x1000

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


#-------------------------------------------
# Post build updates - DEP, HEX, DWO/ELF
#-------------------------------------------
all :
ifeq ($(DEPRULES),1)
#--------------------------
# Dependency file updates
#--------------------------
postbuild : $(PRODUCT_DEP)

$(PRODUCT_DEP): $(PRODUCT)
	@echo "### Updating dependency files ..."
	PowerShell -ExecutionPolicy Bypass -command "& '$(DEPFILE_UPDATE)'"
	@echo "### Done Updating dependency files ..."
endif

ifeq ($(PRODUCT_TYPE),"executable")
#--------------------------
# ELF to hex converter
#--------------------------
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

#--------------------------
# DWO converter
#--------------------------
postbuild : $(PRODUCT_DWO)

$(PRODUCT_DWO): $(PRODUCT)
	@echo "### Invoking postbuild tool "DWO Converter" on "$<"..."
	$(TI_C2000_SHARED_DIR)/tools/bin/win64/extractDWARF.exe $(OBJCOPYFLAGS_DWO)
	@echo "### Done Invoking postbuild tool "DWO Converter" ..."

endif

#--------------------------
# Dependency based build rule
#--------------------------
ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.d,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)


download : postbuild
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) --output_file=$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


xcp_ext_mode.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_csl.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_csl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_board.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_board.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_pwm.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_pwm.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_qep.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/MW_c28xx_qep.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ert_main.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


motorkitc2000_with_controller_working.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/motorkitc2000_with_controller_working.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


motorkitc2000_with_controller_working_data.obj : $(START_DIR)/motorkitc2000_with_controller_working_ert_rtw/motorkitc2000_with_controller_working_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_common.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_classic_trigger.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_standard.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_daq.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_calibration.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_fifo.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_transport.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_mem_default.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_drv_rtiostream.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_utils.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common/xcp_utils.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_frame_serial.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_param_default_serial.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sysctl.obj : D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/sysctl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2837xDBoard_Realtime_Support.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/c2837xDBoard_Realtime_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGlobalInterrupts.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGlobalInterrupts.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


dma.obj : D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_CpuTimers.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CpuTimers.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_DefaultISR.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_GlobalVariableDefs.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_PieCtrl.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_PieVect.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_SysCtrl.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_usDelay.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_usDelay.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


F2837xD_CodeStartBranch.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_CodeStartBranch.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


F2837xD_Dma.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Adc.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Gpio.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


F2837xD_Ipc_Driver_Lite.obj : D:/ti/C2000Ware_4_00_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Lite.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2000HardwareTimerConfig.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/tic2000/src/c2000HardwareTimerConfig.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGPIO.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/MW_c28xGPIO.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


clb.obj : D:/ti/C2000Ware_4_00_00_00/driverlib/f2837xd/driverlib/clb.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2837xDSchedulerTimer0.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/c2837xDSchedulerTimer0.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtiostream_serial_c28x_ext_xcp.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/rtiostream_serial_c28x_ext_xcp.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


datamodify_xcp.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/shared/supportpackages/tic2000/src/datamodify_xcp.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2000HardwareTimerSupport.obj : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/tic2000/src/c2000HardwareTimerSupport.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### OBJCOPYFLAGS_DWO = $(OBJCOPYFLAGS_DWO)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."


