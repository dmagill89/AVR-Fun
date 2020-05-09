/*
This code will toggle each LED if no switch is pressed,
else it will turn on the LED corresponding to the switch that is pressed.
----Timer based-----
U.C. Irvine Extension
X497.32
Instructor: Saleem Yamani
*/

// http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8331-8-and-16-bit-AVR-Microcontroller-XMEGA-AU_Manual.pdf
// See section 14 on timer

#include "devreg.h"

#define MAX_LEDS 2
#define FAST_RESPONSE 0
#define LED_DELAY 255
#define TC0_CK_1024 7
#define OVFIF  1 // Overflow bit

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
	
	do
	{
		val = *((volatile unsigned char *)addr);
	}while( (val != *((volatile unsigned char *)addr)) );

	return (val);
}


void timer_init(void)
{

	//Program the timer with the value you want which is (256-the
	//number of counts) into TCNT0.

	WriteReg(TCC0_CTRLA , TC0_CK_1024);
	WriteReg(TCC0_CNTL, 256-LED_DELAY);
	WriteReg(TCC0_CNTH, 0xff);
	// Clear Overflow bit
	WriteReg(TCC0_INTFLAGS, OVFIF);

}

void Toggle_LEDs(unsigned char This_LED)
{
	
	// writing 0 to this led to turn on
	WriteReg(OUTTGL_R,This_LED);
	//delay(100);
		timer_init();
 	/* Poll the TIFR for an overflow in TOV0. That means the counter 
	   has expired. Or get interrupted */
		while ( !(*((volatile unsigned char *)TCC0_INTFLAGS) & OVFIF));
	
	// writing 0 to this led to turn on
	//WriteReg(OUTTGL_R,This_LED);
	//delay(100);

	// writing 1's to all leds to turn off
	WriteReg(OUT_R,0xFF);
	//delay(100);
		timer_init();
 	/* Poll the TIFR for an overflow in TOV0. That means the counter 
	   has expired. Or get interrupted */
		while ( !(*((volatile unsigned char *)TCC0_INTFLAGS) & OVFIF));

}


int main(void)
{
	
	unsigned char LED_Switch,mask,LED_index,This_LED;
	#if (FAST_RESPONSE)
	unsigned char new_Switch_value; //smy
	#endif

	WriteReg(DIR_R, 0xff);
	//WriteReg(DIR_F, 0x00);
	//WriteReg(PIN1CTRL_PORTF, 0x18 );
	//WriteReg(PIN2CTRL_PORTF, 0x18 );
	
	while(1) {
		mask = 1;
		
		//read LED switches
		// the value for a pushed switch will be 0, all else
		// will be 1
		LED_Switch = ReadReg(IN_F);
		LED_Switch = LED_Switch >>1; // bring switch 1 and 2 values to bit 0 and 1 position
//LED_Switch = 0xff; //smy debug
//This_LED = 0xFE;


		// if no switch is pushed, cyle thru all LEDS
		if( (LED_Switch & 0x3) == 0x3)
		{
			LED_Switch = 0;
		}

		//new_Switch_value = LED_Switch;

		for(LED_index=0; LED_index < MAX_LEDS; LED_index++)
		{
			
			This_LED = (~LED_Switch) & mask;

			Toggle_LEDs(This_LED);

			mask = mask << 1;
			#if (FAST_RESPONSE)
			new_Switch_value = ReadReg(PINA);
			if(new_Switch_value == 0xff)
			{
				new_Switch_value = 0;
			}
			if ( new_Switch_value != LED_Switch)
			break;
			#endif
		}
		
		
	}

	return(0);
}


