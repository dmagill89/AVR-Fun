/*
 * devreg.h
 *
 * Created: 10/20/2019 4:37:30 PM
 *  Author: David Magill
 */ 


#ifndef DEVREG_H_
#define DEVREG_H_

#define PORT_R 0x7e0
#define LEDS 0x7e7
#define CLEAR 0x7e6

void WriteReg(unsigned int addr, unsigned int value);
int ReadReg(unsigned int addr);

#endif /* DEVREG_H_ */