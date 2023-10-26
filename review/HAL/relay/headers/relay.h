/*
 * relay.h
 *
 * Created: 24/10/2023 12:17:22 ص
 *  Author: Muhammed
 */ 


#ifndef RELAY_H_
#define RELAY_H_

#include "../../../MCAL/DIO/headers/DIO.h"

typedef struct {
	DIO_pin_number_t pin_number:5;
	logic_t state_init:1;
	uint8_t reserved:2;
	} relay_t;

void relay_init(const relay_t relay);
void relay_set_logic(const relay_t relay,logic_t stat_init);
void relay_toggle(const relay_t);

#endif /* RELAY_H_ */