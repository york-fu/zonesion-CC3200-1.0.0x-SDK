//*****************************************************************************
// startup_ewarm.c
//
// Startup code for use with IAR IDE.
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include "hw_types.h"
#include "hw_ints.h"
#include "interrupt.h"

//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
void ResetISR(void);
static void IntDefaultHandler(void);


//*****************************************************************************
//
// The entry point for the application startup code.
//
//*****************************************************************************

extern void __iar_program_start(void);


//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************

static unsigned long pulStack[256] @ ".noinit";


//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************
__root const uVectorEntry __vector_table[] @ ".intvec" =
{
    { .ulPtr = (unsigned long)pulStack + sizeof(pulStack) },
                                            // The initial stack pointer
    ResetISR,                               // The reset handler
    IntDefaultHandler,                      // The NMI handler
    IntDefaultHandler,                      // The hard fault handler
    IntDefaultHandler,                      // The MPU fault handler
    IntDefaultHandler,                      // The bus fault handler
    IntDefaultHandler,                      // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // SVCall handler
    IntDefaultHandler,                      // Debug monitor handler
    0,                                      // Reserved
    IntDefaultHandler,                      // The PendSV handler
    IntDefaultHandler,                      // The SysTick handler
    IntDefaultHandler,                      // GPIO Port A
    IntDefaultHandler,                      // GPIO Port B
    IntDefaultHandler,                      // GPIO Port C
    IntDefaultHandler,                      // GPIO Port D
    0,                                      // Reserved
    IntDefaultHandler,                      // UART0 Rx and Tx
    IntDefaultHandler,                      // UART1 Rx and Tx
    0,                                      // Reserved
    IntDefaultHandler,                      // I2C0 Master and Slave
    0,0,0,0,0,                              // Reserved
    IntDefaultHandler,                      // ADC Channel 0
    IntDefaultHandler,                      // ADC Channel 1
    IntDefaultHandler,                      // ADC Channel 2
    IntDefaultHandler,                      // ADC Channel 3
    IntDefaultHandler,                      // Watchdog Timer
    IntDefaultHandler,                      // Timer 0 subtimer A
    IntDefaultHandler,                      // Timer 0 subtimer B
    IntDefaultHandler,                      // Timer 1 subtimer A
    IntDefaultHandler,                      // Timer 1 subtimer B
    IntDefaultHandler,                      // Timer 2 subtimer A
    IntDefaultHandler,                      // Timer 2 subtimer B
    0,0,0,0,                                // Reserved
    IntDefaultHandler,                      // Flash
    0,0,0,0,0,                              // Reserved
    IntDefaultHandler,                      // Timer 3 subtimer A
    IntDefaultHandler,                      // Timer 3 subtimer B
    0,0,0,0,0,0,0,0,0,                      // Reserved
    IntDefaultHandler,                      // uDMA Software Transfer
    IntDefaultHandler,                      // uDMA Error
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    0,0,0,0,0,0,0,0,0,0,                    // Reserved
    IntDefaultHandler,                      // SHA
    0,0,                                    // Reserved
    IntDefaultHandler,                      // AES
    0,                                      // Reserved
    IntDefaultHandler,                      // DES
    0,0,0,0,0,                              // Reserved
    IntDefaultHandler,                      // SDHost
    0,                                      // Reserved
    IntDefaultHandler,                      // I2S
    0,                                      // Reserved
    IntDefaultHandler,                      // Camera
    0,0,0,0,0,0,0,                          // Reserved
    IntDefaultHandler,                      // NWP to APPS Interrupt
    IntDefaultHandler,                      // Power, Reset and Clock module
    0,0,                                    // Reserved
    IntDefaultHandler,                      // Shared SPI
    IntDefaultHandler,                      // Generic SPI
    IntDefaultHandler,                      // Link SPI
};

//*****************************************************************************
//
//! This is the code that gets called when the processor first starts execution
//! following a reset event.  Only the absolutely necessary set is performed,
//! after which the application supplied entry() routine is called.  Any fancy
//! actions (such as making decisions based on the reset cause register, and
//! resetting the bits in that register) are left solely in the hands of the
//! application.
//
//*****************************************************************************
void
ResetISR(void)
{
    //
    // Call the application's entry point.
    //
    __iar_program_start();
}

//*****************************************************************************
//
//! This is the code that gets called when the processor receives an unexpected
//! interrupt.  This simply enters an infinite loop, preserving the system state
//! for examination by a debugger.
//
//*****************************************************************************
static void
IntDefaultHandler(void)
{
    //
    // Go into an infinite loop.
    //
    while(1)
    {
    }
}
