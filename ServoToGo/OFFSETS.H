/*
 * offsets.h
 *
 * Define offsets for various registers on Servo To Go, Inc. Servo I/O card.
 *
 * Copyright (c) 1995, 1998 Servo To Go, Inc.
 * 8117 Groton Ln.
 * Indianapolis, IN 46260
 *
 * For registers in the "high page", an offset of 0x400 is included.
 */
#define CNT0_D     0x00
#define CNT1_D     0x01
#define CNT0_C     0x02
#define CNT1_C     0x03
#define CNT2_D     0x04
#define CNT3_D     0x05
#define CNT2_C     0x06
#define CNT3_C     0x07
#define CNT4_D     0x08
#define CNT5_D     0x09
#define CNT4_C     0x0a
#define CNT5_C     0x0b
#define CNT6_D     0x0c
#define CNT7_D     0x0d
#define CNT6_C     0x0e
#define CNT7_C     0x0f
#define DAC_0      0x10
#define DAC_1      0x12
#define DAC_2      0x14
#define DAC_3      0x16
#define DAC_4      0x18
#define DAC_5      0x1a
#define DAC_6      0x1c
#define DAC_7      0x1e
#define ADC        0x410
#define ADC_0      0x410
#define ADC_1      0x412
#define ADC_2      0x414
#define ADC_3      0x416
#define ADC_4      0x418
#define ADC_5      0x41a
#define ADC_6      0x41c
#define ADC_7      0x41e
#define CNTRL0     0x401     /* Model 2 */
#define DIO_A      0x400     /* Model 1 */
#define DIO_B      0x402     /* Model 1 */
#define DIO_C      0x404     /* Model 1 */
#define DIO_D      0x401     /* Model 1 */
#define PORT_A     0x400     /* Model 2, replaces DIO_A */
#define PORT_B     0x402     /* Model 2, replaces DIO_B */
#define PORT_C     0x404     /* Model 2, replaces DIO_C */
#define PORT_D     0x405     /* Model 2, replaces DIO_D */
#define INTC       0x405     /* Model 1 */
#define BRDTST     0x403
#define MIO_1      0x406
#define ABC_DIR    0x406     /* Model 2 */
#define MIO_2      0x407
#define D_DIR      0x407     /* Model 2 */
#define ODDRST     0x407
#define TIMER_0    0x408
#define TIMER_1    0x40a
#define TIMER_2    0x40c
#define TMRCMD     0x40e
#define ICW1       0x409
#define ICW2       0x40b
#define OCW1       0x40b
#define OCW2       0x409
#define OCW3       0x409
#define IRRreg     0x409   // there's something called IRR in ntddk.h
#define ISR        0x409
#define IDLEN      0x409
#define IMR        0x40b
#define SELDI      0x40b
#define IDL        0x40d
#define CNTRL1     0x40f

/*
 * Some bit masks for various registers
 */
// for IRR, ISR, and IMR
#define IXEVN      0x80
#define IXODD      0x40
#define LIXEVN     0x20
#define LIXODD     0x10
#define EOC        0x08
#define TP0        0x04
#define USR_INT    0x02
#define TP2        0x01
// for INTC
#define AUTOZERO   0x80
#define IXLVL      0x40
#define IXS1       0x20
#define IXS0       0x10
#define USRINT     0x08
#define IA2        0x04
#define IA1        0x02
#define IA0        0x01

#define CNTRL0_AZ   0x80
#define CNTRL0_AD2  0x40
#define CNTRL0_AD1  0x20
#define CNTRL0_AD0  0x10
#define CNTRL0_CAL  0x08
#define CNTRL0_IA2  0x04
#define CNTRL0_IA1  0x02
#define CNTRL0_IA0  0x01

#define CNTRL1_WDTOUT    0x80
#define CNTRL1_INT_G2    0x40
#define CNTRL1_INT_T0    0x10
#define CNTRL1_INT_T2    0x20
#define CNTRL1_NOT_SLAVE 0x08
#define CNTRL1_IEN_G2    0x04
#define CNTRL1_IEN_T0    0x01
#define CNTRL1_IEN_T2    0x02

#define BRDTST_EOC       0x08

/*
 * We're hardwired to irq 5 (sorry).  This is normally reserved for
 * lpt2, but most people don't have two printers.  Sometimes a modem,
 * sound card, etc. will be using this interrupt.  It would be easiest
 * to remove any offending card temporarily.  Otherwise you'll have
 * to figure out how to change the following define's.
 */
/*
#define INTR 13              // irq5 is short 13
#define INT_MASK 0x20        // mask for motherboard interrupt controller
#define IC_ADD   0x20        // address of the interrupt controller on your
                             // motherboard (NOT the one on the Servo To Go
                             // board).  For low numbered interrupts (0-7)
                             // it's 0x20, for higher numbered interrupts
                             // (8-15) it's 0xa0
#define EOI_5    0x65        // Specific EOI for IRQ 5 (used with above)
#define IC_MASK  0x21        // The interrupt mask register on your
                             // motherboard
*/

#define  IRQSL   0x84        // IRQ selection for INTC register
// end of irq related defines
