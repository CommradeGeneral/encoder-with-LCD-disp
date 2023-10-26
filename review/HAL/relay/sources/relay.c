/*
 * relay.c
 *
 * Created: 24/10/2023 01:10:30 ص
 *  Author: Muhammed
 */ 
#include "../headers/relay.h"

void relay_init(const relay_t relay){
	DIO_set_direction_pin(relay.pin_number,OUTPUT);
	DIO_write_pin(relay.pin_number,relay.state_init);
}

void relay_set_logic(const relay_t relay,logic_t stat){
	DIO_write_pin(relay.pin_number,stat);
}

void relay_toggle(const relay_t relay){
	DIO_toggle_pin(relay.pin_number);
}
