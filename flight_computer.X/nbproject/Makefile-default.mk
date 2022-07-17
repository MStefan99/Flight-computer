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
FINAL_IMAGE=${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c ../src/config/default/peripheral/tc/plib_tc0.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/lib/src/dma.cpp ../src/lib/src/i2c.cpp ../src/lib/src/lps22.cpp ../src/lib/src/lsm303.cpp ../src/lib/src/servo.cpp ../src/lib/src/updates.cpp ../src/lib/src/receiver.cpp ../src/lib/src/pc.cpp ../src/lib/src/mpu6050.cpp ../src/lib/src/AttitudeEstimator.cpp ../src/lib/src/EKF.cpp ../src/lib/src/Matrix.cpp ../src/lib/src/util.cpp ../src/lib/src/PID.cpp ../src/main.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o ${OBJECTDIR}/_ext/829342655/plib_tc0.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/116683680/dma.o ${OBJECTDIR}/_ext/116683680/i2c.o ${OBJECTDIR}/_ext/116683680/lps22.o ${OBJECTDIR}/_ext/116683680/lsm303.o ${OBJECTDIR}/_ext/116683680/servo.o ${OBJECTDIR}/_ext/116683680/updates.o ${OBJECTDIR}/_ext/116683680/receiver.o ${OBJECTDIR}/_ext/116683680/pc.o ${OBJECTDIR}/_ext/116683680/mpu6050.o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ${OBJECTDIR}/_ext/116683680/EKF.o ${OBJECTDIR}/_ext/116683680/Matrix.o ${OBJECTDIR}/_ext/116683680/util.o ${OBJECTDIR}/_ext/116683680/PID.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1984496892/plib_clock.o.d ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/829342769/plib_pm.o.d ${OBJECTDIR}/_ext/1865521619/plib_port.o.d ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o.d ${OBJECTDIR}/_ext/829342655/plib_tc0.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/116683680/dma.o.d ${OBJECTDIR}/_ext/116683680/i2c.o.d ${OBJECTDIR}/_ext/116683680/lps22.o.d ${OBJECTDIR}/_ext/116683680/lsm303.o.d ${OBJECTDIR}/_ext/116683680/servo.o.d ${OBJECTDIR}/_ext/116683680/updates.o.d ${OBJECTDIR}/_ext/116683680/receiver.o.d ${OBJECTDIR}/_ext/116683680/pc.o.d ${OBJECTDIR}/_ext/116683680/mpu6050.o.d ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d ${OBJECTDIR}/_ext/116683680/EKF.o.d ${OBJECTDIR}/_ext/116683680/Matrix.o.d ${OBJECTDIR}/_ext/116683680/util.o.d ${OBJECTDIR}/_ext/116683680/PID.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o ${OBJECTDIR}/_ext/829342655/plib_tc0.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/116683680/dma.o ${OBJECTDIR}/_ext/116683680/i2c.o ${OBJECTDIR}/_ext/116683680/lps22.o ${OBJECTDIR}/_ext/116683680/lsm303.o ${OBJECTDIR}/_ext/116683680/servo.o ${OBJECTDIR}/_ext/116683680/updates.o ${OBJECTDIR}/_ext/116683680/receiver.o ${OBJECTDIR}/_ext/116683680/pc.o ${OBJECTDIR}/_ext/116683680/mpu6050.o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ${OBJECTDIR}/_ext/116683680/EKF.o ${OBJECTDIR}/_ext/116683680/Matrix.o ${OBJECTDIR}/_ext/116683680/util.o ${OBJECTDIR}/_ext/116683680/PID.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c ../src/config/default/peripheral/tc/plib_tc0.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/lib/src/dma.cpp ../src/lib/src/i2c.cpp ../src/lib/src/lps22.cpp ../src/lib/src/lsm303.cpp ../src/lib/src/servo.cpp ../src/lib/src/updates.cpp ../src/lib/src/receiver.cpp ../src/lib/src/pc.cpp ../src/lib/src/mpu6050.cpp ../src/lib/src/AttitudeEstimator.cpp ../src/lib/src/EKF.cpp ../src/lib/src/Matrix.cpp ../src/lib/src/util.cpp ../src/lib/src/PID.cpp ../src/main.cpp

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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAML10E16A
MP_LINKER_FILE_OPTION=,--script="..\src\config\default\ATSAML10E16A.ld"
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
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/23b72014ffbbc3647bbc0a115d34e1518e0b592a .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/e408d1f984a23f1911abbfa7e9711c2892351afc .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/7ee9243f45ef44ea387478eef37f67a79109aa47 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/d0e62ec1c058087b23188859a354b9bb96dc5178 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/66ab854ae7f2ad73f96dba729118d1b327c8d126 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/57924f365bc2a91a96ce4f14be50d7ba1e610593 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/4e95f0e91b056f3e9ee0afc9da564c48f8bf5718 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c  .generated_files/flags/default/7fd835295c9dfe5128eb81df626bab2282fbd632 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342655/plib_tc0.o: ../src/config/default/peripheral/tc/plib_tc0.c  .generated_files/flags/default/72b61d832a7e69b8a76651711b4d4c7fd41ac873 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/829342655" 
	@${RM} ${OBJECTDIR}/_ext/829342655/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342655/plib_tc0.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342655/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/829342655/plib_tc0.o ../src/config/default/peripheral/tc/plib_tc0.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/12f852a21dc39411443d953277fd3dce69906331 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/5443ed99bc1ff5498d61a5cfb443abcce8583fa6 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/e8141c6f5a37d7e6f0de91f9a49b85f147e1a00a .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/4f6150335dddeb74ab17057f6caa7ac564471455 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/42e0de7546ba5c813d7c178d435fc36bffb2d108 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/417f74b4efdf29ddd43b2258d98accaf4d41f02c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/ef007127fcb3a0fbb0611b1922bdfe4d366d0a90 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/94e4407e4832f282b79bc6881ee8d4c3177a374d .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/cc55eaec14fe1efde00ce78378ed1024b608ad8c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/d8fe28dd3f8aa8f3a853e24d8eeea227bdd3469a .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/6e753d5d0d603865340d19215f0d98196931a63d .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/423913dd68cadf9f904c37971019322a51f3072d .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/f9c591398084624287e3d73e72dea9c48378b4b2 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c  .generated_files/flags/default/bcfa7fcdf984d04a3ce31bef8bd3705ed614a363 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom0_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom0_i2c_master.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342655/plib_tc0.o: ../src/config/default/peripheral/tc/plib_tc0.c  .generated_files/flags/default/71e8f97442dff4fdd1424f5cd7087cb09704aab1 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/829342655" 
	@${RM} ${OBJECTDIR}/_ext/829342655/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342655/plib_tc0.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/829342655/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/829342655/plib_tc0.o ../src/config/default/peripheral/tc/plib_tc0.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/4deb5f6a0d83d64be1ead5c137b018d6fae3702a .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/70252f3232b6c4d9b89d31d5f76b1b992edc4a13 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/d17f77180ce685398cdc2ac4a1e8aba408441e5b .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/bf3a32935ae8a54c581d2d89a1ff5630534a4bbd .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/eccde95e4b5edc66081c8ccd567ea1d2ee64e746 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/6b020771e95225d0c8b9b7d08da9f5ec6993619b .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CPPC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/116683680/dma.o: ../src/lib/src/dma.cpp  .generated_files/flags/default/94f3e2220fcd042d3ec1d7a9259d99001cebe940 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/dma.o.d" -o ${OBJECTDIR}/_ext/116683680/dma.o ../src/lib/src/dma.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/i2c.o: ../src/lib/src/i2c.cpp  .generated_files/flags/default/9dfe07f06e9776043ac959e0558b59c73912400a .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/i2c.o.d" -o ${OBJECTDIR}/_ext/116683680/i2c.o ../src/lib/src/i2c.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lps22.o: ../src/lib/src/lps22.cpp  .generated_files/flags/default/388ff7a29c1cba5082c74f295260ad6416fcc6d .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lps22.o.d" -o ${OBJECTDIR}/_ext/116683680/lps22.o ../src/lib/src/lps22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lsm303.o: ../src/lib/src/lsm303.cpp  .generated_files/flags/default/dc0cc8294b60de33f80699c3b24328132a618b48 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lsm303.o.d" -o ${OBJECTDIR}/_ext/116683680/lsm303.o ../src/lib/src/lsm303.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/servo.o: ../src/lib/src/servo.cpp  .generated_files/flags/default/882f841b1078577e013a529027bcdde1573de102 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/servo.o.d" -o ${OBJECTDIR}/_ext/116683680/servo.o ../src/lib/src/servo.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/updates.o: ../src/lib/src/updates.cpp  .generated_files/flags/default/eca3bbea7f82964e43c0a176cbcc9e4b7ef5f8a4 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/updates.o.d" -o ${OBJECTDIR}/_ext/116683680/updates.o ../src/lib/src/updates.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/receiver.o: ../src/lib/src/receiver.cpp  .generated_files/flags/default/229ba7c963e8b2aa58f98d2665501e7e87abfc36 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/receiver.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/receiver.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/receiver.o.d" -o ${OBJECTDIR}/_ext/116683680/receiver.o ../src/lib/src/receiver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/pc.o: ../src/lib/src/pc.cpp  .generated_files/flags/default/f7398e421cdb683dd2fc2f42311d6e2e5b88749b .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/pc.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/pc.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/pc.o.d" -o ${OBJECTDIR}/_ext/116683680/pc.o ../src/lib/src/pc.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/mpu6050.o: ../src/lib/src/mpu6050.cpp  .generated_files/flags/default/805c1964eeb5ac6c3e68aa299912dfdb23285aa4 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/mpu6050.o.d" -o ${OBJECTDIR}/_ext/116683680/mpu6050.o ../src/lib/src/mpu6050.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o: ../src/lib/src/AttitudeEstimator.cpp  .generated_files/flags/default/1ba4fccd7dd391cecbe7c5897fc98857e0c446ee .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d" -o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ../src/lib/src/AttitudeEstimator.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/EKF.o: ../src/lib/src/EKF.cpp  .generated_files/flags/default/f973119bd5a0562758ba39d8d5a629156955f659 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/EKF.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/EKF.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/EKF.o.d" -o ${OBJECTDIR}/_ext/116683680/EKF.o ../src/lib/src/EKF.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/Matrix.o: ../src/lib/src/Matrix.cpp  .generated_files/flags/default/a7c522bd587848f3567079bcd08f7f2729cd14cf .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/Matrix.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/Matrix.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/Matrix.o.d" -o ${OBJECTDIR}/_ext/116683680/Matrix.o ../src/lib/src/Matrix.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/util.o: ../src/lib/src/util.cpp  .generated_files/flags/default/dac9e9172a06b8c6ac22badf2f93024015d22027 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/util.o.d" -o ${OBJECTDIR}/_ext/116683680/util.o ../src/lib/src/util.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/PID.o: ../src/lib/src/PID.cpp  .generated_files/flags/default/32f6157ea06cf789cb38f737f045fc345c1bdc73 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/PID.o.d" -o ${OBJECTDIR}/_ext/116683680/PID.o ../src/lib/src/PID.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp  .generated_files/flags/default/23fd0570b5646471920b50995626ff050e4c9d4c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/116683680/dma.o: ../src/lib/src/dma.cpp  .generated_files/flags/default/e3c03cdc903e54c18221034c72f76446c7785e9 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/dma.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/dma.o.d" -o ${OBJECTDIR}/_ext/116683680/dma.o ../src/lib/src/dma.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/i2c.o: ../src/lib/src/i2c.cpp  .generated_files/flags/default/4623cf54685dda57842537bfac7faf0e888c8a8c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/i2c.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/i2c.o.d" -o ${OBJECTDIR}/_ext/116683680/i2c.o ../src/lib/src/i2c.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lps22.o: ../src/lib/src/lps22.cpp  .generated_files/flags/default/299cd45a4db54faaab8bad78d98e256027a4cad2 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lps22.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lps22.o.d" -o ${OBJECTDIR}/_ext/116683680/lps22.o ../src/lib/src/lps22.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/lsm303.o: ../src/lib/src/lsm303.cpp  .generated_files/flags/default/fc4a5610dba670d7c65449315a7f24d39ad8184b .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/lsm303.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/lsm303.o.d" -o ${OBJECTDIR}/_ext/116683680/lsm303.o ../src/lib/src/lsm303.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/servo.o: ../src/lib/src/servo.cpp  .generated_files/flags/default/1db35dd36e3013f3eb075ad237151820ca9c9f9b .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/servo.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/servo.o.d" -o ${OBJECTDIR}/_ext/116683680/servo.o ../src/lib/src/servo.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/updates.o: ../src/lib/src/updates.cpp  .generated_files/flags/default/8165e455bf696de7b518a03f462794b38397a4d4 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/updates.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/updates.o.d" -o ${OBJECTDIR}/_ext/116683680/updates.o ../src/lib/src/updates.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/receiver.o: ../src/lib/src/receiver.cpp  .generated_files/flags/default/38f6c38c6a01f3fc9bb03ab91dab3dd5b9593465 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/receiver.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/receiver.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/receiver.o.d" -o ${OBJECTDIR}/_ext/116683680/receiver.o ../src/lib/src/receiver.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/pc.o: ../src/lib/src/pc.cpp  .generated_files/flags/default/ff1db8ac8f8f8c53b7c6091356bf259efeb8c45c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/pc.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/pc.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/pc.o.d" -o ${OBJECTDIR}/_ext/116683680/pc.o ../src/lib/src/pc.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/mpu6050.o: ../src/lib/src/mpu6050.cpp  .generated_files/flags/default/bbfd4e8dd71491fce8b2efa1c4384c0535920e3d .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/mpu6050.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/mpu6050.o.d" -o ${OBJECTDIR}/_ext/116683680/mpu6050.o ../src/lib/src/mpu6050.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o: ../src/lib/src/AttitudeEstimator.cpp  .generated_files/flags/default/970106a584ec686233d7a70982b312889abdf791 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o.d" -o ${OBJECTDIR}/_ext/116683680/AttitudeEstimator.o ../src/lib/src/AttitudeEstimator.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/EKF.o: ../src/lib/src/EKF.cpp  .generated_files/flags/default/c608413e682630016ec3860e23f3fd3c9718e957 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/EKF.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/EKF.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/EKF.o.d" -o ${OBJECTDIR}/_ext/116683680/EKF.o ../src/lib/src/EKF.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/Matrix.o: ../src/lib/src/Matrix.cpp  .generated_files/flags/default/24a35fd9f56dbbf54a7a0fdcfc0561c70fe00df8 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/Matrix.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/Matrix.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/Matrix.o.d" -o ${OBJECTDIR}/_ext/116683680/Matrix.o ../src/lib/src/Matrix.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/util.o: ../src/lib/src/util.cpp  .generated_files/flags/default/8673119c49d0acc2b66a34ab59a55de7bb137dea .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/util.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/util.o.d" -o ${OBJECTDIR}/_ext/116683680/util.o ../src/lib/src/util.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/116683680/PID.o: ../src/lib/src/PID.cpp  .generated_files/flags/default/4ac8d0f1e39804889bef704f444ed415bf10536c .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/116683680" 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o.d 
	@${RM} ${OBJECTDIR}/_ext/116683680/PID.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/116683680/PID.o.d" -o ${OBJECTDIR}/_ext/116683680/PID.o ../src/lib/src/PID.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp  .generated_files/flags/default/42b5549e02ef3a92e4a5148b59f75a12c6ff9a01 .generated_files/flags/default/4b7f45486c60851d5b0f88ca2b5a399e1f7f33f5
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-rtti -fno-exceptions -fno-check-new -fno-enforce-eh-specs -ffunction-sections -fdata-sections -I"../src" -I"../src/config/default" -I"../src/packs/ATSAML10E16A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp   -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wno-unused-variable -mdfp="${DFP_DIR}" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/ATSAML10E16A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -fno-rtti -fno-exceptions -mno-device-startup-code -o ${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=128,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/ATSAML10E16A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -fno-rtti -fno-exceptions -mno-device-startup-code -o ${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=128,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/flight_computer.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
