/*
	

	nullDC-Beagle build configuration options

	fine grained options
	HOST_OS,HOST_CPU, ..

	build-level options
	TARGET_BEAGLE, TARGET_WIN86, ...

	code shouldn't depend on build level options whenever possible
*/

//ndc configs

#define NO_MMU
//#define HOST_NO_REC

#define DC_PLATFORM_MASK        7
#define DC_PLATFORM_NORMAL      0   /* Works, for the most part */
#define DC_PLATFORM_DEV_UNIT    1   /* This is missing hardware */
#define DC_PLATFORM_NAOMI       2   /* Works, for the most part */ 
#define DC_PLATFORM_NAOMI2      3   /* Needs to be done, 2xsh4 + 2xpvr + custom TNL */
#define DC_PLATFORM_ATOMISWAVE  4   /* Needs to be done, DC-like hardware with possibly more ram */
#define DC_PLATFORM_HIKARU      5   /* Needs to be done, 2xsh4, 2x aica , custom vpu */
#define DC_PLATFORM_AURORA      6   /* Needs to be done, Uses newer 300 mhz sh4 + 150 mhz pvr mbx SoC */
 

#define DC_PLATFORM DC_PLATFORM_NORMAL


//Target platform configs
//HOST_OS
#define OS_WINDOWS   0x10000001
#define OS_LINUX     0x10000002
#define OS_DARWIN    0x10000003

//HOST_CPU
#define CPU_X86      0x20000001
#define CPU_ARM      0x20000002
#define CPU_MIPS     0x20000003
#define CPU_X64      0x20000004

//BUILD_COMPILER
#define COMPILER_VC  0x30000001
#define COMPILER_GCC 0x30000002

#if defined(_WIN32) && !defined(TARGET_WIN86)
	#define TARGET_WIN86
#endif

#ifdef __GNUC__ 
	#define BUILD_COMPILER COMPILER_GCC
#else
	#define BUILD_COMPILER COMPILER_VC
#endif

#ifdef TARGET_WIN86
	#define HOST_OS OS_WINDOWS
	#define HOST_CPU CPU_X86
#elif TARGET_PANDORA
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_ARM
#elif TARGET_LINUX_ARMELv7
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_ARM
#elif TARGET_LINUX_x86
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_X86
#elif TARGET_LINUX_MIPS
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_MIPS
#elif TARGET_GCW0
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_MIPS
#elif TARGET_NACL32
	#define HOST_OS OS_LINUX
	#define HOST_CPU CPU_X86
#elif TARGET_IPHONE
    #define HOST_OS OS_DARWIN
    #define HOST_CPU CPU_ARM
#else
	#error Invalid Target: TARGET_* not defined
#endif

#ifdef HOST_NO_REC
	#ifndef HOST_NO_AREC
		#define HOST_NO_AREC 1
	#endif
#endif
