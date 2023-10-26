/*
 * DC_motor.c
 *
 * Created: 24/10/2023 01:22:17 ص
 *  Author: Muhammed
 */ 
#include "../headers/DC_motor.h"

void DC_motor_init(DC_motor_t DC_motor){
	DIO_set_direction_pin(DC_motor.forward,OUTPUT);
	DIO_set_direction_pin(DC_motor.reverse,OUTPUT);
	switch (DC_motor.dir_init){
		case NO_MOTION:
			DIO_write_pin(DC_motor.forward,LOW);
			DIO_write_pin(DC_motor.reverse,LOW);
		break;
		
		case FORWARD:
			DIO_write_pin(DC_motor.forward,HIGH);
			DIO_write_pin(DC_motor.reverse,LOW);
		break;
		
		case REVERSE:
			DIO_write_pin(DC_motor.forward,LOW);
			DIO_write_pin(DC_motor.reverse,HIGH);
		break;
		
		default:
			//empty
		break;
	}
}

void DC_motor_set_direction(DC_motor_t DC_motor,DC_motor_direction_t direction){
	switch (direction){
		case NO_MOTION:
			DIO_write_pin(DC_motor.forward,LOW);
			DIO_write_pin(DC_motor.reverse,LOW);
		break;
		
		case FORWARD:
			DIO_write_pin(DC_motor.forward,HIGH);
			DIO_write_pin(DC_motor.reverse,LOW);
		break;
		
		case REVERSE:
			DIO_write_pin(DC_motor.forward,LOW);
			DIO_write_pin(DC_motor.reverse,HIGH);
		break;
		
		default:
			//empty
		break;
	}
}

void DC_motor_stop(DC_motor_t DC_motor){
	DIO_write_pin(DC_motor.forward,LOW);
	DIO_write_pin(DC_motor.reverse,LOW);
}