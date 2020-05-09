/*
This code will Turn ON and OFF all the LEDS
U.C. Irvine Extension
X497.32
Instructor: Saleem Yamani
*/
#include "devreg.h"

#define DELAY_CNT 200

void delay(unsigned int val)
{
	unsigned int temp;
	volatile unsigned int temp2;

	for(temp = 0; temp < val; temp++)
	for (temp2 = 0; temp2 < val; temp2 ++) ;
}

/* wrapper for writing register */
void WriteReg(unsigned int addr, unsigned char val)
{
	*((volatile unsigned char *)addr) = val;

}

/* wrapper for Reading register */
unsigned char ReadReg(unsigned int addr)
{
	unsigned char val;
	
	val = *((volatile unsigned char *)addr);

	return (val);
}

int main(void)
{
	
	// Set PORTR DATA Direction (DIRR) as output
	WriteReg(DIR_R, 0xff);

	for(;;)
	{
		// Toggle LED0 and LED1
		WriteReg(OUTTGL_R,0x3);
		delay(DELAY_CNT);
	}

}
