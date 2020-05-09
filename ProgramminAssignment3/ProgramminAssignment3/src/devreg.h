/*
 * devreg.h
 *
 * Created: 10/26/2019 7:37:49 PM
 *  Author: David Magill
 */ 


#ifndef DEVREG_H_
#define DEVREG_H_

#define DELAY_COUNT	200

#define PORTF		0x6A0
#define PORTF_IN	0x6A8
#define PORTR		0x7E0
#define LEDS		0x7E7
#define CLEAR		0x7E6

void delay(unsigned int delay);
void WriteReg(unsigned int addr, unsigned int value);
int ReadReg(unsigned int addr);

void blinkLEDs(unsigned int value1, unsigned int value2);

#endif /* DEVREG_H_ */