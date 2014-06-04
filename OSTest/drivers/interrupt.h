/*
 * interrupt.h
 *	Driver level interrupt support. Directly interfaces
 *	with Broadcom registers.
 *  Created on: Mar 21, 2014
 *      Author: Phillip
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define ARM_INTERRUPT_REG_OFFSET	0x2000B000
#define IRQ_BASIC_PENDING			0x2000B200
#define IRQ_PENDING1				0x2000B204
#define IRQ_PENDING2				0x2000B208
#define FIQ_CONTROL					0x2000B20C
#define IRQ_ENABLE1					0x2000B210
#define IRQ_ENABLE2					0x2000B214
#define IRQ_BASIC_ENABLE			0x2000B218
#define IRQ_DISABLE1				0x2000B21C
#define IRQ_DISABLE2				0x2000B220
#define IRQ_BASIC_DISABLE			0x2000B224

/* ARM PERIPHERAL INTERRUPTS (indices 0-63) */
#define ARMP_AUXILLIARY_INDEX		29
#define ARMP_I2C_SPI_SLAVE_INDEX	43
#define ARMP_PWA0_INDEX				45
#define ARMP_PWA1_INDEX				46
#define ARMP_SMI_INDEX				48
#define ARMP_GPIO_INDEX_0			49
#define ARMP_GPIO_INDEX_1			50
#define ARMP_GPIO_INDEX_2			51
#define ARMP_GPIO_INDEX_3			52
#define ARMP_I2C_INDEX				53
#define ARMP_SPI_INDEX				54
#define	ARMP_PCM_INDEX				55
#define ARMP_UART_INDEX				56

/* ARM INTERRUPTS (indices 0-7) */
#define ARM_TIMER_INDEX				0
#define ARM_MAILBOX_INDEX			1
#define ARM_DOORBELL0_INDEX			2
#define ARM_DOORBELL1_INDEX			3
#define ARM_GPIO0_HALTED_INDEX		4
#define ARM_GPIO1_HALTED_INDEX		5
#define ARM_ILLEGAL_ACCESS0_INDEX	6
#define ARM_ILLEGAL_ACCESS1_INDEX	7

//  FUTURE NOTES:
//	There are some weird notes in BCM datasheet
//  If a GPU pending IRQ is in IRQ_BASIC (7,9,10,18,19,53,54,55,56,57)
//  it will not be reflected in get_irq_pendingX_is_set
//
//

extern unsigned char get_irq_basic_pending(unsigned char index);
extern unsigned char get_gpu_irq_pending(unsigned char index);
extern unsigned char get_arm_irq_pending(unsigned char index);
extern unsigned char get_irq_pending1_is_set(unsigned char index);
extern unsigned char get_irq_pending2_is_set(unsigned char index);
extern void enable_fiq();
extern unsigned char get_fiq_enabled_status();
//0 <= source <= 127
extern void set_fiq_source(unsigned char source);
extern unsigned char get_fiq_source();
extern void enable_gpu_irq(unsigned char index);
extern unsigned char get_gpu_irq_enabled_status(unsigned char index);
extern void enable_arm_irq(unsigned char index);
extern unsigned char get_arm_irq_enabled_status(unsigned char index);
extern void disable_gpu_irq(unsigned char index);
extern unsigned char get_gpu_irq_disabled_status();
extern void disable_arm_irq(unsigned char index);
extern unsigned get_arm_irq_disabled_status(unsigned char index);


#endif /* INTERRUPT_H_ */
