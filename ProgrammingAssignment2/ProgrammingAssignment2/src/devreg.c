/*
 * devreg.c
 *
 * Created: 10/20/2019 4:47:09 PM
 *  Author: David Magill
 */ 
#include "devreg.h"

void WriteReg(unsigned int addr, unsigned int value) {
	*((volatile unsigned char *)addr) = value;
}

int ReadReg(unsigned int addr) {
	return *((volatile unsigned char *)addr);
}