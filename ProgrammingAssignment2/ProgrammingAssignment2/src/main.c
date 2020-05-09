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
//#include <asf.h>
#include "devreg.h"

int main (void)
{
	/* insert application code here, after the board has been initialized. */
	
	// set portb data direction (ddrb) as output
	WriteReg(PORT_R, 0xff);
	
	
	while (1) {
		// turn led0 on and led 1 off, by writing 0xfe to portb, bit 0 set to 0 to turn on led 0
		volatile unsigned int currentCycle = 0;
		
		WriteReg(LEDS, 0b1110);
		
		while(currentCycle < 32768) {
			currentCycle++;
		}
		
		WriteReg(LEDS, 0b1111);

	}
}