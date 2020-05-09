/*
* devreg.c
*
* Created: 10/26/2019 7:37:36 PM
*  Author: David Magill
*/
#include "devreg.h"

//void blinkLEDs(void) {
	//
	//unsigned int blink = 1;
	//
	//while (blink) {
		//WriteReg(LEDS, 0xFE);
		//delay(DELAY_COUNT);
		//WriteReg(LEDS, 0xFD);
		//
		//if ((ReadReg(PORTF_IN) & (1 << 1)) != 0x00 && (ReadReg(PORTF_IN) & (1 << 2)) != 0x00) {
			//blink = 0;
		//}
	//}
//}
//
//void blinkLED0(void) {
	//
	//unsigned int blink = 1;
	//
	//while (blink) {
		//WriteReg(LEDS, 0xFE);
		//delay(DELAY_COUNT);
		//WriteReg(LEDS, 0xFF);
		//
		//if ((ReadReg(PORTF_IN) & ( 1 << 1)) != 0x00) {
			//blink = 0;
		//}
	//}
//}
//
//void blinkLED1(void) {
	//
	//unsigned int blink = 1;
	//
	//while (blink) {
		//WriteReg(LEDS, 0xFD);
		//delay(DELAY_COUNT);
		//WriteReg(LEDS, 0xFF);
		//
		//if ((ReadReg(PORTF_IN) & (1 << 2)) != 0x00) {
			//blink = 0;
		//}
	//}
//}
//
//void delay(unsigned int delay) {
	//
	//unsigned int temp;
	//volatile unsigned int temp2;
//
	//for(temp = 0; temp < delay; temp++){	
		//for (temp2 = 0; temp2 < delay; temp2 ++);
	//}
//}
//
//void WriteReg(unsigned int addr, unsigned int value) {
	//*((volatile unsigned char *)addr) = value;
//}
//
//int ReadReg(unsigned int addr) {
	//unsigned char regValue;
	//
	//regValue = *((volatile unsigned char *)addr);
	//
	//return (regValue);
//}