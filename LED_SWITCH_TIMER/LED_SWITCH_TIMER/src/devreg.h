/*
 * devreg.h
 *
 * Created: 2/19/2018 10:19:15 PM
 *  Author: Saleem Yamani
 */ 


#ifndef DEVREG_H_
#define DEVREG_H_

#define DIR_R  0x7E0 //Data Direction Register, Port R
#define OUT_R  0x7E4 //Data OUT Register, Port R

#define OUTTGL_R 0x7E7 //Toggle Output PORT R

#define DIR_F  0x6A0 //Data Direction Register, Port F
#define IN_F  0x6A8 //Data IN Register, Port F

#define PIN1CTRL_PORTF           0x6B1 // DIR_F+0x11  /*!< Pin 1 Configuration */
#define PIN2CTRL_PORTF           0x6B2 //DIR_F+0x12  /*!< Pin 2 Configuration */

#define PIN2CTRL_PULL_UP          (3 << 0x3)  /*!< Pull up when input */

#define TCC0_CTRLA 0x800
#define TCC0_CNTL 0x820  //Count low
#define TCC0_CNTH 0x821  //Count high
#define TCC0_INTFLAGS 0x80C

#endif /* DEVREG_H_ */