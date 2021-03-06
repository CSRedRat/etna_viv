/****************************************************************************
*
*    Copyright (C) 2005 - 2011 by Vivante Corp.
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the license, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not write to the Free Software
*    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*
*****************************************************************************/




#ifndef __gc_hal_options_h_
#define __gc_hal_options_h_

/*
    USE_NEW_LINUX_SIGNAL

    This define enables the Linux kernel signaling between kernel and user.
*/
#ifndef USE_NEW_LINUX_SIGNAL
#   define USE_NEW_LINUX_SIGNAL     0
#endif

/*
    NO_USER_DIRECT_ACCESS_FROM_KERNEL

    This define enables the Linux kernel behavior accessing user memory.
*/
#ifndef NO_USER_DIRECT_ACCESS_FROM_KERNEL
#   define NO_USER_DIRECT_ACCESS_FROM_KERNEL        0
#endif

/*
    VIVANTE_PROFILER

    This define enables the profiler.
*/
#ifndef VIVANTE_PROFILER
#   define VIVANTE_PROFILER         0
#endif

/*
    gcdUSE_VG

    Enable VG HAL layer (only for GC350).
*/
#ifndef gcdUSE_VG
#   define gcdUSE_VG                0
#endif

/*
    USE_SW_FB

    Set to 1 if the frame buffer memory cannot be accessed by the GPU.
*/
#ifndef USE_SW_FB
#define USE_SW_FB                   0
#endif

/*
    USE_SHADER_SYMBOL_TABLE

    This define enables the symbol table in shader object.
*/
#define USE_SHADER_SYMBOL_TABLE     1

/*
    USE_SUPER_SAMPLING

    This define enables super-sampling support.
*/
#define USE_SUPER_SAMPLING          0

/* PROFILE_HAL_COUNTERS, PROFILE_HW_COUNTERS, PROFILE_SHADER_COUNTERS are not runtime configurable. */
/*
    PROFILE_HAL_COUNTERS

    This define enables HAL counter profiling support.
    HW and SHADER Counter profiling depends on this.
*/
/*
#define PROFILE_HAL_COUNTERS        1
*/
/*
    PROFILE_HW_COUNTERS

    This define enables HW counter profiling support.
*/
/*
#define PROFILE_HW_COUNTERS         1
*/
/*
    PROFILE_SHADER_COUNTERS

    This define enables SHADER counter profiling support.
*/
/*
#define PROFILE_SHADER_COUNTERS     1
*/
/*
    COMMAND_PROCESSOR_VERSION

    The version of the command buffer and task manager.
*/
#define COMMAND_PROCESSOR_VERSION   1

/*
    gcdDUMP

        When set to 1, a dump of all states and memory uploads, as well as other
        hardware related execution will be printed to the debug console.  This
        data can be used for playing back applications.
*/
#define gcdDUMP                     0

/*
    gcdDUMP_API

        When set to 1, a high level dump of the EGL and GL/VG APs's are
        captured.
*/
#define gcdDUMP_API                 0

/*
    gcdDUMP_IN_KERNEL

        When set to 1, all dumps will happen in the kernel.  This is handy if
        you want the kernel to dump its command buffers as well and the data
        needs to be in sync.
*/
#define gcdDUMP_IN_KERNEL           0

/*
    gcdDUMP_COMMAND

        When set to non-zero, the command queue will dump all incoming command
        and context buffers as well as all other modifications to the command
        queue.
*/
#define gcdDUMP_COMMAND             0

/*
    gcdNULL_DRIVER
*/
#define gcdNULL_DRIVER              0

/*
    gcdENABLE_TIMEOUT_DETECTION

    Enable timeout detection.
*/
#define gcdENABLE_TIMEOUT_DETECTION 0

/*
    gcdCMD_BUFFERS

    Number of command buffers to use per client.  Each command buffer is 32kB in
    size.
*/
#define gcdCMD_BUFFERS              2

/*
    gcdPOWER_CONTROL_DELAY

    The delay in milliseconds required to wait until the GPU has woke up from a
    suspend or power-down state.  This is system dependent because the bus clock
    also needs to be stabalize.
*/
#define gcdPOWER_CONTROL_DELAY      1

/*
    gcdMMU_SIZE

    Size of the MMU page table in bytes.  Each 4 bytes can hold 4kB worth of
    virtual data.
*/
#define gcdMMU_SIZE                 (128 << 10)

/*
    gcdSECURE_USER

    Use logical addresses instead of physical addresses in user land.  In this
    case a hint table is created for both command buffers and context buffers,
    and that hint table will be used to patch up those buffers in the kernel
    when they are ready to submit.
*/
#define gcdSECURE_USER                      0

/*
    gcdSECURE_CACHE_SLOTS

    Number of slots in the logical to DMA address cache table.  Each time a
    logical address needs to be translated into a DMA address for the GPU, this
    cache will be walked.  The replacement scheme is LRU.
*/
#define gcdSECURE_CACHE_SLOTS               64

/*
    gcdREGISTER_ACCESS_FROM_USER

    Set to 1 to allow IOCTL calls to get through from user land.  This should
    only be in debug or development drops.
*/
#ifndef gcdREGISTER_ACCESS_FROM_USER
#   define gcdREGISTER_ACCESS_FROM_USER     1
#endif

/*
    gcdHEAP_SIZE

    Set the allocation size for the internal heaps.  Each time a heap is full,
    a new heap will be allocated with this minmimum amount of bytes.  The bigger
    this size, the fewer heaps there are to allocate, the better the
    performance.  However, heaps won't be freed until they are completely free,
    so there might be some more memory waste if the size is too big.
*/
#define gcdHEAP_SIZE                (64 << 10)

/*
    gcdNO_POWER_MANAGEMENT

    This define disables the power management code.
*/
#ifndef gcdNO_POWER_MANAGEMENT
#   define gcdNO_POWER_MANAGEMENT           0
#endif

/*
    gcdFPGA_BUILD

    This define enables work arounds for FPGA images.
*/
#if !defined(gcdFPGA_BUILD)
#   define gcdFPGA_BUILD                    0
#endif

/*
    gcdGPU_TIMEOUT

    This define specified the number of milliseconds the system will wait before
    it broadcasts the GPU is stuck.  In other words, it will define the timeout
    of any operation that needs to wait for the GPU.

    If the value is 0, no timeout will be checked for.
*/
#if !defined(gcdGPU_TIMEOUT)
#   define gcdGPU_TIMEOUT                   0
#endif

#endif /* __gc_hal_options_h_ */

