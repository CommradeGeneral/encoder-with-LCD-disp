/*
* EXT_INT.c
*
* Created: 25/10/2023 03:33:34 م
*  Author: Muhammed
*/
#include "../headers/EXT_INT.h"

#define INT0_VECTOR		__vector_1
#define INT1_VECTOR		__vector_2
#define INT2_VECTOR		__vector_3

void INT0_VECTOR (void) __attribute__ ((signal));
void INT1_VECTOR (void) __attribute__ ((signal));
void INT2_VECTOR (void) __attribute__ ((signal));


static void (*INT0_callback_function)(void) = NULL;
static void (*INT1_callback_function)(void) = NULL;
static void (*INT2_callback_function)(void) = NULL;



void INTx_init(uint8_t INTx,uint8_t sense_control,active_t int_enable){
	switch(INTx){
		case 0:
		MCUCR.INT0_sense_CTRL = sense_control;
		GICR.INT0 = int_enable;
		DIO_set_direction_pin(DIO_pin_D2,INPUT);
		DIO_enable_disable_pull_up_pin(DIO_pin_D2,ENABLE);
		break;
		
		case 1:
		MCUCR.INT1_sense_CTRL = sense_control;
		GICR.INT1 = int_enable;
		DIO_set_direction_pin(DIO_pin_D3,INPUT);
		DIO_enable_disable_pull_up_pin(DIO_pin_D3,ENABLE);
		break;
		
		case 2:
		MCUCSR.INT2_sense_CTRL = sense_control;
		GICR.INT2 = int_enable;
		DIO_set_direction_pin(DIO_pin_B2,INPUT);
		DIO_enable_disable_pull_up_pin(DIO_pin_B2,ENABLE);
		break;
		
		default:
		// empty
		break;
	}
}

void INTx_set_sense_control(uint8_t INTx,uint8_t sense_control){
	switch(INTx){
		case 0:
		MCUCR.INT0_sense_CTRL = sense_control;
		break;
		
		case 1:
		MCUCR.INT1_sense_CTRL = sense_control;
		break;
		
		case 2:
		MCUCSR.INT2_sense_CTRL = sense_control;
		break;
		
		default:
		// empty
		break;
	}
}


void INTx_interrupt_enable(uint8_t INTx){
	switch(INTx){
		case 0:
		GICR.INT0 = ENABLE;
		break;
		
		case 1:
		GICR.INT1 = ENABLE;
		break;
		
		case 2:
		GICR.INT2 = ENABLE;
		break;
		
		default:
		// empty
		break;
	}

}
void INTx_interrupt_disable(uint8_t INTx){
	switch(INTx){
		case 0:
		GICR.INT0 = ENABLE;
		break;
		
		case 1:
		GICR.INT1 = ENABLE;
		break;
		
		case 2:
		GICR.INT2 = ENABLE;
		break;
		
		default:
		// empty
		break;
	}

}


void INTx_ISR_callback(uint8_t INTx,void (*callback)(void)){
	switch(INTx){
		case 0:
		INT0_callback_function = callback;
		break;
		
		case 1:
		INT1_callback_function = callback;
		break;
		
		case 2:
		INT0_callback_function = callback;
		break;
		
		default:
		//empty
		break;
	}
}


void INT0_VECTOR(void) {
	INT0_callback_function();
}


void INT1_VECTOR(void) {
	INT1_callback_function();
	
}

void INT2_VECTOR(void) {
	INT2_callback_function();
}