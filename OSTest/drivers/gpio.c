#include <gpio.h>
#include <core.h>

//0 <= n <= 53
//0 <= val <= 1 unless otherwise stated.
unsigned char gpio_getgpfseln(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int basemask = 0b111;
	int shift = 3 * (n % 10);
	switch (n / 10) {
	case 0:
		return (GET32(GPFSEL0) & (basemask << shift)) >> shift;
	case 1:
		return (GET32(GPFSEL1) & (basemask << shift)) >> shift;
	case 2:
		return (GET32(GPFSEL2) & (basemask << shift)) >> shift;
	case 3:
		return (GET32(GPFSEL3) & (basemask << shift)) >> shift;
	case 4:
		return (GET32(GPFSEL4) & (basemask << shift)) >> shift;
	case 5:
		return (GET32(GPFSEL5) & (basemask << shift)) >> shift;
	default:
		//error
		return 0;
		break;
	}
	return 0;
}
//0 <= val <= 7
void gpio_setgpfseln(unsigned char n, unsigned char val) {
	if (n > 53 || val > 7) {
		return;
	}
	int mask = ~(0b111 << 3 * (n % 10));
	switch (n / 10) {
	case 0:
		PUT32(GPFSEL0,
				(mask & GET32(GPFSEL0)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	case 1:
		PUT32(GPFSEL1,
				(mask & GET32(GPFSEL1)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	case 2:
		PUT32(GPFSEL2,
				(mask & GET32(GPFSEL2)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	case 3:
		PUT32(GPFSEL3,
				(mask & GET32(GPFSEL3)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	case 4:
		PUT32(GPFSEL4,
				(mask & GET32(GPFSEL4)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	case 5:
		PUT32(GPFSEL5,
				(mask & GET32(GPFSEL5)) | ((val & 0b111) << 3 * (n % 10)));
		break;
	default:
		break;
	}
}
void gpio_gpsetn(unsigned char n) {
	if (n > 53) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPSET0, (mask & GET32(GPSET0)) | (1 << n % 32));
		break;
	case 1:
		PUT32(GPSET1, (mask & GET32(GPSET1)) | (1 << n % 32));
		break;
	}
}
void gpio_gpclrn(unsigned char n) {
	if (n > 53) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPCLR0, (mask & GET32(GPCLR0)) | (1 << n % 32));
		break;
	case 1:
		PUT32(GPCLR1, (mask & GET32(GPCLR1)) | (1 << n % 32));
		break;
	}
}
unsigned char gpio_getgplevn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPSET0) & mask) >> (n % 32);
	case 1:
		return (GET32(GPSET1) & mask) >> (n % 32);
	}
	return 0;
}
void gpio_setgplevn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPLEV0, (mask & GET32(GPLEV0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPLEV1, (mask & GET32(GPLEV1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgpedsn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPEDS0) & mask) >> n % 32;
	case 1:
		return (GET32(GPEDS1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_cleargpedsn(unsigned char n) {
	if (n > 53) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPLEV0, mask & GET32(GPLEV1));
		break;
	case 1:
		PUT32(GPLEV1, mask & GET32(GPLEV1));
		break;
	}
}
unsigned char gpio_getgprenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPREN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPREN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgprenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPREN0, (mask & GET32(GPREN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPREN1, (mask & GET32(GPREN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgpfenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPFEN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPFEN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgpfenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPFEN0, (mask & GET32(GPFEN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPFEN1, (mask & GET32(GPFEN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgphenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPHEN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPHEN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgphenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPHEN0, (mask & GET32(GPHEN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPHEN1, (mask & GET32(GPHEN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgplenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPLEN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPLEN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgplenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPLEN0, (mask & GET32(GPLEN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPLEN1, (mask & GET32(GPLEN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgparenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPAREN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPAREN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgparenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPAREN0, (mask & GET32(GPAREN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPAREN1, (mask & GET32(GPAREN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgpafenn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPAFEN0) & mask) >> n % 32;
	case 1:
		return (GET32(GPAFEN1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgpafenn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPAFEN0, (mask & GET32(GPAFEN0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPAFEN1, (mask & GET32(GPAFEN1)) | ((val & 1) << n % 32));
		break;
	}
}
unsigned char gpio_getgppud(void) {
	return GET32(GPPUD) & 0b11;
}
//0 <= val <= 3
void gpio_setgppud(unsigned char val) {
	if (val > 3) {
		return;
	}
	PUT32(GPPUD, val & 0b11);
}
unsigned char gpio_getgppudclkn(unsigned char n) {
	if (n > 53) {
		return 0;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		return (GET32(GPPUDCLK0) & mask) >> n % 32;
	case 1:
		return (GET32(GPPUDCLK1) & mask) >> n % 32;
	}
	return 0;
}
void gpio_setgppudclkn(unsigned char n, unsigned char val) {
	if (n > 53 || val > 1) {
		return;
	}
	int mask = ~(1 << n % 32);
	switch (n / 32) {
	case 0:
		PUT32(GPPUDCLK0, (mask & GET32(GPPUDCLK0)) | ((val & 1) << n % 32));
		break;
	case 1:
		PUT32(GPPUDCLK1, (mask & GET32(GPPUDCLK1)) | ((val & 1) << n % 32));
		break;
	}
}
