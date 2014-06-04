/*
 * gpio.h
 *	Interface designed to interact directly with
 *	the Broadcom BCM2835's GPIO registers.
 *	Provides access to all fields but provides no
 *	GPIO usage abstractions.
 *  Created on: Feb 27, 2014
 *      Author: Phillip
 */

#ifndef GPIO_H_
#define GPIO_H_

#define GPFSEL0 	0x20200000
#define GPFSEL1 	0x20200004
#define GPFSEL2 	0x20200008
#define GPFSEL3 	0x2020000C
#define GPFSEL4 	0x20200010
#define GPFSEL5 	0x20200014
#define GPSET0  	0x2020001C
#define GPSET1 		0x20200020
#define GPCLR0  	0x20200028
#define GPCLR1		0x2020002C
#define GPLEV0		0x20200034
#define GPLEV1		0x20200038
#define GPEDS0		0x20200040
#define GPEDS1		0x20200044
#define GPREN0		0x2020004C
#define GPREN1		0x20200050
#define GPFEN0		0x20200058
#define GPFEN1		0x2020005C
#define GPHEN0		0x20200064
#define GPHEN1		0x20200068
#define GPLEN0		0x20200070
#define GPLEN1		0x20200074
#define GPAREN0		0x2020007C
#define GPAREN1		0x20200080
#define GPAFEN0		0x20200088
#define GPAFEN1		0x2020008C
#define GPPUD		0x20200094
#define GPPUDCLK0	0x20200098
#define GPPUDCLK1	0x2020009C

#define GPIOFSEL_OUTPUT	1
#define GPIOFSEL_INPUT 	0
#define GPIOFSEL_F0		0b100
#define GPIOFSEL_F1		0b101
#define GPIOFSEL_F2		0b110
#define GPIOFSEL_F3		0b111
#define GPIOFSEL_F4		0b011
#define GPIOFSEL_F5		0b010

//0 <= n <= 53
//0 <= val <= 1 unless otherwise stated.
extern unsigned char gpio_getgpfseln(unsigned char n);
//0 <= val <= 7
extern void gpio_setgpfseln(unsigned char n,unsigned char val);
extern void gpio_gpsetn(unsigned char n);
extern void gpio_gpclrn(unsigned char n);
extern unsigned char gpio_getgplevn(unsigned char n);
extern void gpio_setgplevn(unsigned char n,unsigned char val);
extern unsigned char gpio_getgpedsn(unsigned char n);
extern void gpio_cleargpedsn(unsigned char n);
extern unsigned char gpio_getgprenn(unsigned char n);
extern void gpio_setgprenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgpfenn(unsigned char n);
extern void gpio_setgpfenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgphenn(unsigned char n);
extern void gpio_setgphenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgplenn(unsigned char n);
extern void gpio_setgplenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgparenn(unsigned char n);
extern void gpio_setgparenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgpafenn(unsigned char n);
extern void gpio_setgpafenn(unsigned char n, unsigned char val);
extern unsigned char gpio_getgppud(void);
//0 <= val <= 3
extern void gpio_setgppud(unsigned char val);
extern unsigned char gpio_getgppudclkn(unsigned char n);
extern void gpio_setgppudclkn(unsigned char n, unsigned char val);

#endif /* GPIO_H_ */
