#include <timer.h>
#include <core.h>

unsigned char get_system_timer_matchN(unsigned char n) {
	if(n >= 0 && n<4) {
		unsigned int mask = 1 << n;
		return GET32(CS) & mask;
	}
	else {
		return 0;
	}

}
void set_system_timer_matchN(unsigned char n, unsigned char value) {
	if(n >= 0 && n<4) {
		unsigned int mask = ~(1 << n);
		SET32(CS, (GET32(CS) & mask) | ((value & 1) << n));
	}
}
unsigned int get_clo() {
	return GET32(CLO);
}
unsigned int get_chi() {
	return GET32(CHI);
}
unsigned int get_system_timer(unsigned char n) {
	switch(n) {
	case 0:
		return GET32(C0);
	case 1:
		return GET32(C1);
	case 2:
		return GET32(C2);
	case 3:
		return GET32(C3);
	default:
		return -1;
	}
}
void set_system_timer(unsigned char n, unsigned int val) {
	switch(n) {
	case 0:
		PUT32(C0, val);
		break;
	case 1:
		PUT32(C1, val);
		break;
	case 2:
		PUT32(C2, val);
		break;
	case 3:
		PUT32(C3, val);
		break;
	}
}

void clear_timerN(unsigned char n) {
	if(n >= 0 && n<4) {
		unsigned int mask = ~(1 << n);
		SET32(CS, (GET32(CS) & mask) | (1 << n));
	}
}
void start_timerN(unsigned char n, unsigned int time) {

}

void create_timer(unsigned int timeout, unsigned char repeat) {
	//set interrupts up?
	//set start timer
	//setup handler
}
