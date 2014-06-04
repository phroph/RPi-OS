/*
 * timer.h
 *
 *  Created on: May 30, 2014
 *      Author: Phillip
 */

#ifndef TIMER_H_
#define TIMER_H_

#define CS 	0x2003000
#define CLO 0x2003004
#define CHI 0x2003008
#define C0	0x200300C
#define C1 	0x2003010
#define C2	0x2003014
#define C3	0x2003018

//0 <= n <= 3, 0,2 reserved
extern unsigned char get_system_timer_matchN(unsigned char n);
extern void set_system_timer_matchN(unsigned char n, unsigned char value);
extern unsigned int get_clo();
extern unsigned int get_chi();
extern unsigned int get_system_timer(unsigned char n);
extern void set_system_timer(unsigned char n, unsigned int val);

extern void clear_timerN(unsigned char n);
extern void start_timerN(unsigned char n, unsigned int time);

extern void create_timer(unsigned int timeout, unsigned char repeat);

#endif /* TIMER_H_ */
