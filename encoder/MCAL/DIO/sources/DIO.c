/*
 * DIO.c
 *
 * Created: 23/10/2023 09:34:26 م
 *  Author: Muhammed
 */ 
#include "../headers/DIO.h"

static volatile uint8_t* const PORTx[4] = {	(uint8_t*)0x3B,
											(uint8_t*)0x38,
											(uint8_t*)0x35,
											(uint8_t*)0x32};

static volatile uint8_t* const DDRx[4] = {	(uint8_t*)0x3A,
											(uint8_t*)0x37,
											(uint8_t*)0x34,
											(uint8_t*)0x31};
											
static volatile uint8_t* const PINx[4] = {	(uint8_t*)0x39,
											(uint8_t*)0x36,
											(uint8_t*)0x33,
											(uint8_t*)0x30};


void DIO_set_direction_pin(DIO_pin_number_t pin,DIO_direction_t direction){
	switch (direction)
	{
		case OUTPUT:
			SET_BIT(*DDRx[(uint8_t)pin / 8],(uint8_t)pin % 8);
		break;
		
		case INPUT:
			CLEAR_BIT(*DDRx[(uint8_t)pin / 8],(uint8_t)pin % 8);
		break;
		
		default:
			// empty
		break;
	}
}
void DIO_write_pin(DIO_pin_number_t pin,logic_t logic){
	switch(logic){
		case HIGH:
			SET_BIT(*PORTx[(uint8_t)pin / 8],(uint8_t)pin % 8);
		break;
		
		case LOW:
			CLEAR_BIT(*PORTx[(uint8_t)pin / 8],(uint8_t)pin % 8);
		break;
		
		default:
			//empty
		break;
	}
}


void DIO_toggle_pin(DIO_pin_number_t pin){
	TOGGLE_BIT(*PORTx[(uint8_t)pin / 8],(uint8_t)pin % 8);
}

logic_t DIO_read_pin(DIO_pin_number_t pin){
	return READ_BIT(*PINx[(uint8_t)pin / 8],(uint8_t)pin % 8);
}

void DIO_enable_disable_pull_up_pin(DIO_pin_number_t pin,active_t logic){
	uint8_t arg1 = (uint8_t) pin / 8;
	uint8_t arg2 = (uint8_t) pin % 8;
	if (!READ_BIT(*DDRx[arg1],arg2)) {
		switch (logic) {
			case ENABLE: 
				SET_BIT(*PORTx[arg1],arg2);
			break;
			
			case DISABLE:
				CLEAR_BIT(*PORTx[arg1],arg2);
			break;
			
			default:
				//empty
			break;
		}
	} else {
		// empty
	}
}

void DIO_set_direction_port(DIO_port_t port, uint8_t data){
	*DDRx[(uint8_t) port] = data;
}
void DIO_write_port(DIO_port_t port, uint8_t data){
	*PORTx[(uint8_t) port] = (data & (*DDRx[(uint8_t) port]));
}

void DIO_toggle_port(DIO_port_t port){
	(*PORTx[(uint8_t) port]) ^= (0xFF & (*DDRx[(uint8_t) port]));
}

void DIO_toggle_masked_port(DIO_port_t port,uint8_t mask){
	(*PORTx[(uint8_t) port]) ^= (0xFF & mask & (*DDRx[(uint8_t) port]));
}

uint8_t DIO_read_port(DIO_port_t port){
	return *PINx[(uint8_t) port];
}

void DIO_enable_disable_pull_up_port(DIO_port_t port,uint8_t data){
	*PORTx[(uint8_t) port] = (data & ~(*DDRx[(uint8_t) port]));
}

void DIO_enable_disable_pull_up_port_with_mask(DIO_port_t port,uint8_t data, uint8_t mask){
	*PORTx[(uint8_t) port] = (data & mask & ~(*DDRx[(uint8_t) port]));
}