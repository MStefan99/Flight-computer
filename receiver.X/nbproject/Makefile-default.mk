#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/lib/src/dma.cpp ../src/lib/src/i2c.cpp ../src/lib/src/lps22.cpp ../src/lib/src/lsm303.cpp ../src/lib/src/mpu6050.cpp ../src/lib/src/PID.cpp ../src/lib/src/servo.cpp ../src/lib/src/uart.cpp ../src/lib/src/updates.cpp ../src/lib/src/usb.cpp ../src/lib/src/usb_descriptors.cpp ../src/lib/src/util.cpp ../src/lib/src/sbus.cpp ../src/main.cpp ../src/lib/src/AttitudeEstimator.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/116683680/dma.o ${OBJECTDIR}/_ext/116683680/i2c.o ${OBJECTDIR}/_ext/116683680/lps22.o ${OBJECTDIR}/_ext/116683680/lsm303.o ${OBJECTDIR}/_ext/116683680/mpu6050.o ${OBJECTDIR}/_ext/116683680/PID.o ${OBJECTDIR}/_ext/116683680/servo.o ${OBJECTDIR}/_ext/116683680/uart.o ${OBJECTDIR}/_ext/116683680/updates.o ${OBJECTDIR}/_ext/116683680/usb.o ${OBJECTDIR}/_ext/116683680/usb_descriptors.o ${OBJECTDIR}/_ext/116683680/util.o ${OBJECTDIR}/_ext/116683680/sbus.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1984496892/plib_clock.o.d ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/829342769/plib_pm.o.d ${OBJECTDIR}/_ext/1865521619/plib_port.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/116683680/dma.o.d ${OBJECTDIR}/_ext/116683680/i2c.o.d ${OBJECTDIR}/_ext/116683680/lps22.o.d ${OBJECTDIR}/_ext/116683680/lsm303.o.d ${OBJECTDIR}/_ext/116683680/mpu6050.o.d ${OBJECTDIR}/_ext/116683680/PID.o.d ${OBJECTDIR}/_ext/116683680/servo.o.d ${OBJECTDIR}/_ext/116683680/uart.o.d ${OBJECTDIR}/_ext/116683680/updates.o.d ${OBJECTDIR}/_ext/116683680/usb.o.d ${OBJECTDIR}/_ext/116683680/usb_descriptors.o.d ${OBJECTDIR}/_ext/116683680/util.o.d ${OBJECTDIR}/_ext/116683680/sbus.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/116683680/dma.o ${OBJECTDIR}/_ext/116683680/i2c.o ${OBJECTDIR}/_ext/116683680/lps22.o ${OBJECTDIR}/_ext/116683680/lsm303.o ${OBJECTDIR}/_ext/116683680/mpu6050.o ${OBJECTDIR}/_ext/116683680/PID.o ${OBJECTDIR}/_ext/116683680/servo.o ${OBJECTDIR}/_ext/116683680/uart.o ${OBJECTDIR}/_ext/116683680/updates.o ${OBJECTDIR}/_ext/116683680/usb.o ${OBJECTDIR}/_ext/116683680/usb_descriptors.o ${OBJECTDIR}/_ext/116683680/util.o ${OBJECTDIR}/_ext/116683680/sbus.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o

# Source Files
SOURCEFILES=../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/lib/src/dma.cpp ../src/lib/src/i2c.cpp ../src/lib/src/lps22.cpp ../src/lib/src/lsm303.cpp ../src/lib/src/mpu6050.cpp ../src/lib/src/PID.cpp ../src/lib/src/servo.cpp ../src/lib/src/uart.cpp ../src/lib/src/updates.cpp ../src/lib/src/usb.cpp ../src/lib/src/usb_descriptors.cpp ../src/lib/src/util.cpp ../src/lib/src/sbus.cpp ../src/main.cpp ../src/lib/src/AttitudeEstimator.cpp

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAML21E16B
MP_LINKER_FILE_OPTION=,--script="..\src\config\default\ATSAML21E16B.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/90b5cd3e3f71c28d223d8a42003e505a20a7fc1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/a0847511fede65783a92aef68fadef88baefbfae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/f32e7b99bc79101176fccad5872abfd293e9382c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/788d63304e57c6291928d269c9682a56b6813077 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/a8422425cbd24c41b9d5a894b8ab640985b2386a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/9f3d17bf1548b1aa72344d76595ae85d197a210e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/545752a6ac5a630f949e52815848c1e5524ff677 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/141ba86ea16f1b8f408b919f1a2950fb902716b0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/ee98a3a6b704217c6c172cf8e551bc502237beff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/7cd0fabce5753be2ca70c12ca256ca19a4fda20c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/3fd37b41d5a6fb2ea1cc101a173eba770187315f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/b489320b6cde3d5fc6de6127775cf3254cf4e979 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/1b4d93d4fd584f357d9a44d6bb33de755a786625 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/8335fe84d6e75c5ebe17749ed0e98f182f452bde .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/708a17c7563cf3be4f12a9b4491a8ae520a4f9ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/c985d208a17db9a0aeea6a81a57780b1901215a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/4fc0ecb029c35c7a6ce25355d90cd357a4175dc0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/c7f1e9cb9044df021d9b081323fcc778c80fae04 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/ff25782f570daa1d0d71591d117db7b76b4e5087 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/e0e1f5b0fdd943a7ab01734a1b571b577b42143e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/16a90cbb53fb01c7dc9b5f5c3af2ba7f0c99b0dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/ef1a6c897960dc27d0efc4dedcfd8ebf496f1c1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/94213daec58fb82f2452256394df47d2609b069f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/49e1e2dc5311122faf8a5d919759402cfc4573ff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/116683680/dma.o: ../src/lib/src/dma.cpp  .generated_files/flags/default/63eda456e4b10d0c556a2a0231534348e2d23165 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/dma.o.d" -o ${OBJECTDIR}/_ext/116683680/dma.o ../src/lib/src/dma.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/i2c.o: ../src/lib/src/i2c.cpp  .generated_files/flags/default/2bf504466a1cc70aa15567246363099abf7b238d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/i2c.o.d" -o ${OBJECTDIR}/_ext/116683680/i2c.o ../src/lib/src/i2c.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lps22.o: ../src/lib/src/lps22.cpp  .generated_files/flags/default/fa06feb7c8bf68fd5159c92dc9dcd8c878990457 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lps22.o.d" -o ${OBJECTDIR}/_ext/116683680/lps22.o ../src/lib/src/lps22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lsm303.o: ../src/lib/src/lsm303.cpp  .generated_files/flags/default/ee94e12ebb1ebb2e1e84fb6a94686d672efe18a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lsm303.o.d" -o ${OBJECTDIR}/_ext/116683680/lsm303.o ../src/lib/src/lsm303.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/mpu6050.o: ../src/lib/src/mpu6050.cpp  .generated_files/flags/default/70b183b362ad33b2b595e475807209c5f0caeeb4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/mpu6050.o.d" -o ${OBJECTDIR}/_ext/116683680/mpu6050.o ../src/lib/src/mpu6050.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/PID.o: ../src/lib/src/PID.cpp  .generated_files/flags/default/abae464fbb405f8073f53de1ab41ac3a36cfea7f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/PID.o.d" -o ${OBJECTDIR}/_ext/116683680/PID.o ../src/lib/src/PID.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/servo.o: ../src/lib/src/servo.cpp  .generated_files/flags/default/9fff8e7dd239b65b3c2d925de164ca880237018f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/servo.o.d" -o ${OBJECTDIR}/_ext/116683680/servo.o ../src/lib/src/servo.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/uart.o: ../src/lib/src/uart.cpp  .generated_files/flags/default/9f50e35da0251b3a306b0d5895584a3d9da9599 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/uart.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/uart.o.d" -o ${OBJECTDIR}/_ext/116683680/uart.o ../src/lib/src/uart.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/updates.o: ../src/lib/src/updates.cpp  .generated_files/flags/default/e1211652353cd39c16f263bb0be4eeec1c07672b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/updates.o.d" -o ${OBJECTDIR}/_ext/116683680/updates.o ../src/lib/src/updates.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/usb.o: ../src/lib/src/usb.cpp  .generated_files/flags/default/51e6def86577cf6b9bc5fb83ca3f3d09a48646f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/usb.o.d" -o ${OBJECTDIR}/_ext/116683680/usb.o ../src/lib/src/usb.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/usb_descriptors.o: ../src/lib/src/usb_descriptors.cpp  .generated_files/flags/default/b80634d15426e3145512541e1bb4ded99149341d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb_descriptors.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/usb_descriptors.o.d" -o ${OBJECTDIR}/_ext/116683680/usb_descriptors.o ../src/lib/src/usb_descriptors.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/util.o: ../src/lib/src/util.cpp  .generated_files/flags/default/5e2427cd437c070d5a5869df7ecabb48d73af440 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/util.o.d" -o ${OBJECTDIR}/_ext/116683680/util.o ../src/lib/src/util.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/sbus.o: ../src/lib/src/sbus.cpp  .generated_files/flags/default/ab67cc10e539ea6846884b9538b3fd9de6627da9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/sbus.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/sbus.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/sbus.o.d" -o ${OBJECTDIR}/_ext/116683680/sbus.o ../src/lib/src/sbus.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp  .generated_files/flags/default/3adc419230b62eeba85daa91f58d80dc568dc7e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o: ../src/lib/src/AttitudeEstimator.cpp  .generated_files/flags/default/f9fd1bcf80f9f0a0b2503262f0dac8ce9e73584f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d" -o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ../src/lib/src/AttitudeEstimator.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/116683680/dma.o: ../src/lib/src/dma.cpp  .generated_files/flags/default/f4d150d0562a34389a47b0038469a860b3d93149 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/dma.o.d" -o ${OBJECTDIR}/_ext/116683680/dma.o ../src/lib/src/dma.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/i2c.o: ../src/lib/src/i2c.cpp  .generated_files/flags/default/58920682bbee25709621eb5d8f064f58084b95b1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/i2c.o.d" -o ${OBJECTDIR}/_ext/116683680/i2c.o ../src/lib/src/i2c.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lps22.o: ../src/lib/src/lps22.cpp  .generated_files/flags/default/cda3c435437b828e443a6fc3056ac6f07ea220f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lps22.o.d" -o ${OBJECTDIR}/_ext/116683680/lps22.o ../src/lib/src/lps22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lsm303.o: ../src/lib/src/lsm303.cpp  .generated_files/flags/default/d2e032b825d47680671459a0657e3a1213322cd3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lsm303.o.d" -o ${OBJECTDIR}/_ext/116683680/lsm303.o ../src/lib/src/lsm303.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/mpu6050.o: ../src/lib/src/mpu6050.cpp  .generated_files/flags/default/d5e05b3dc5e2cc053114524cfdbee997d6e02d04 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/mpu6050.o.d" -o ${OBJECTDIR}/_ext/116683680/mpu6050.o ../src/lib/src/mpu6050.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/PID.o: ../src/lib/src/PID.cpp  .generated_files/flags/default/f26f59dfbfa2b1061080ec0b8760d6823f304944 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/PID.o.d" -o ${OBJECTDIR}/_ext/116683680/PID.o ../src/lib/src/PID.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/servo.o: ../src/lib/src/servo.cpp  .generated_files/flags/default/d04b36fb552fc2e0d7cc16849b177ecf7d7ed604 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/servo.o.d" -o ${OBJECTDIR}/_ext/116683680/servo.o ../src/lib/src/servo.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/uart.o: ../src/lib/src/uart.cpp  .generated_files/flags/default/e62d4c2507b9efef45e2d4700b422b809bade015 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/uart.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/uart.o.d" -o ${OBJECTDIR}/_ext/116683680/uart.o ../src/lib/src/uart.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/updates.o: ../src/lib/src/updates.cpp  .generated_files/flags/default/3238b4ac5caa1398119963eabef78439fc30056e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/updates.o.d" -o ${OBJECTDIR}/_ext/116683680/updates.o ../src/lib/src/updates.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/usb.o: ../src/lib/src/usb.cpp  .generated_files/flags/default/a64f9dac1a850185fdb9263eb107868ca909d6ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/usb.o.d" -o ${OBJECTDIR}/_ext/116683680/usb.o ../src/lib/src/usb.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/usb_descriptors.o: ../src/lib/src/usb_descriptors.cpp  .generated_files/flags/default/9632a8d1a9f6362f2bcf64817817f47edc5f05af .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/usb_descriptors.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/usb_descriptors.o.d" -o ${OBJECTDIR}/_ext/116683680/usb_descriptors.o ../src/lib/src/usb_descriptors.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/util.o: ../src/lib/src/util.cpp  .generated_files/flags/default/56af38a2c2e0bc80b0d016abfebac0316ae968d1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/util.o.d" -o ${OBJECTDIR}/_ext/116683680/util.o ../src/lib/src/util.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/sbus.o: ../src/lib/src/sbus.cpp  .generated_files/flags/default/fc859f2cbaa168baa9ba14fd4d15d9af67b5cf9e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/sbus.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/sbus.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/sbus.o.d" -o ${OBJECTDIR}/_ext/116683680/sbus.o ../src/lib/src/sbus.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp  .generated_files/flags/default/d449dbf680aafa24f29fddf50bea98332d388640 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o: ../src/lib/src/AttitudeEstimator.cpp  .generated_files/flags/default/a05653b2ec89917ce2dcb6519c18dc1f1f94d889 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML21E16B_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d" -o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ../src/lib/src/AttitudeEstimator.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/saml21b" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/ATSAML21E16B.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/saml21b"
	
else
${DISTDIR}/receiver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/ATSAML21E16B.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/receiver.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/saml21b"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/receiver.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
