/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include "asf.h"
#include "devreg.h"
#include "tc.h"

void blinkLEDs(unsigned int value1, unsigned int value2) {
	while (1) {
		WriteReg(LEDS, value1);
		delayClock();
		WriteReg(LEDS, value2);
	}
}

void delay(unsigned int delay) {
	
	unsigned int temp;
	volatile unsigned int temp2;

	for(temp = 0; temp < delay; temp++) {
		for (temp2 = 0; temp2 < delay; temp2 ++);
	}
}

void clearOVFIF() {
	WriteReg(TCC0_OVFIF, 0x01);
}

void delayClock() {
	// set control register A to 0111 for prescaler 1024
	WriteReg(TCC0_CTRLA, 0b0111);
	WriteReg(TCC0_CNTL, 0x3C);
	// set TCCO counter high to hex ff since it will not be used
	WriteReg(TCC0_CNTH, 0xff);
	
	while (ReadReg(TCC0_CNTL) != 0xff) {}
	
	clearOVFIF();
}

void WriteReg(unsigned int addr, unsigned int value) {
	*((volatile unsigned char *)addr) = value;
}

int ReadReg(unsigned int addr) {
	unsigned char regValue;
	
	regValue = *((volatile unsigned char *)addr);
	
	return (regValue);
}

int main (void)
{
	/* insert application code here, after the board has been initialized. */

	// set portb data direction (ddrb) as output
	WriteReg(PORT_R, 0xff);
	
	while (1) {
		blinkLEDs(0xfe, 0xfd);
	}
}
