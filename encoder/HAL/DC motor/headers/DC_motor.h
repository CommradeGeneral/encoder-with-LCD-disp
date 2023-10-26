/*
 * DC_motor.h
 *
 * Created: 24/10/2023 01:15:04 ص
 *  Author: Muhammed
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "../../../MCAL/DIO/headers/DIO.h"

typedef enum {
	NO_MOTION	= 0,
	FORWARD,
	REVERSE
	} DC_motor_direction_t;

typedef struct {
	DC_motor_direction_t dir_init:2;
	DIO_pin_number_t forward:5;
	DIO_pin_number_t reverse:5;
} DC_motor_t;

void DC_motor_init(DC_motor_t DC_motor);
void DC_motor_set_direction(DC_motor_t DC_motor,DC_motor_direction_t direction);
void DC_motor_stop(DC_motor_t DC_motor);


#endif /* DC_MOTOR_H_ */