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
#include "devreg.h"
#include "asf.h"
#include "tc.h"

volatile unsigned char timer_isr_state = 0;

void blinkLEDs(unsigned int value1, unsigned int value2) {
	while (1) {
		if (timer_isr_state == 0) {
			WriteReg(LEDS, value1);
		}
		else {
			WriteReg(LEDS, value2);
		}
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
	
	while (ReadReg(TCC0_OVFIF) & (1 << 0) != 0) {}
	
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

static void my_callback(void) {
	
	switch (timer_isr_state) {
		case 0:
			timer_isr_state = 1;
			break;
		case 1: 
			timer_isr_state = 0;
			break;
	}
}

void timer_init(void) {
	tc_enable(&TCC0);
	tc_set_overflow_interrupt_callback(&TCC0, my_callback);
	tc_set_wgm(&TCC0, TC_WG_NORMAL);
	tc_write_period(&TCC0, 1000);
	
	tc_set_overflow_interrupt_level(&TCC0, TC_INT_LVL_LO);
	cpu_irq_enable();
	tc_write_clock_source(&TCC0, TC_CLKSEL_DIV1024_gc);
}

int main (void)
{
	pmic_init();
	sysclk_init();
	timer_init();

	// set portb data direction (ddrb) as output
	WriteReg(PORT_R, 0xff);
	WriteReg(LEDS, 0xff); // turn off LEDs by default
	
	blinkLEDs(0xfe, 0xfd);
	
	return 0;
}
