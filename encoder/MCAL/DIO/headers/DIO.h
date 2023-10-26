/*
* DIO.h
*
* Created: 23/10/2023 09:09:16 م
*  Author: Muhammed
*/


#ifndef DIO_H_
#define DIO_H_

#include "../../../generic_library/STD_data_types.h"
#include "../../../generic_library/bit_math.h"


typedef enum {
	INPUT	= 0,
	OUTPUT
} DIO_direction_t;


typedef enum {
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
} DIO_port_t;

typedef enum {
	// port A
	DIO_pin_A0 = 0,
	DIO_pin_A1,
	DIO_pin_A2,
	DIO_pin_A3,
	DIO_pin_A4,
	DIO_pin_A5,
	DIO_pin_A6,
	DIO_pin_A7,
	// port B
	DIO_pin_B0,
	DIO_pin_B1,
	DIO_pin_B2,
	DIO_pin_B3,
	DIO_pin_B4,
	DIO_pin_B5,
	DIO_pin_B6,
	DIO_pin_B7,
	// port C
	DIO_pin_C0,
	DIO_pin_C1,
	DIO_pin_C2,
	DIO_pin_C3,
	DIO_pin_C4,
	DIO_pin_C5,
	DIO_pin_C6,
	DIO_pin_C7,
	// port D
	DIO_pin_D0,
	DIO_pin_D1,
	DIO_pin_D2,
	DIO_pin_D3,
	DIO_pin_D4,
	DIO_pin_D5,
	DIO_pin_D6,
	DIO_pin_D7
} DIO_pin_number_t;



void DIO_set_direction_pin(DIO_pin_number_t pin,DIO_direction_t direction);
void DIO_write_pin(DIO_pin_number_t pin,logic_t logic);
void DIO_toggle_pin(DIO_pin_number_t pin);
logic_t DIO_read_pin(DIO_pin_number_t pin);
void DIO_enable_disable_pull_up_pin(DIO_pin_number_t pin,active_t logic);

void DIO_set_direction_port(DIO_port_t port, uint8_t data);
void DIO_write_port(DIO_port_t port, uint8_t data);
void DIO_toggle_port(DIO_port_t port);
void DIO_toggle_masked_port(DIO_port_t port,uint8_t mask);
uint8_t DIO_read_port(DIO_port_t port);
void DIO_enable_disable_pull_up_port(DIO_port_t port,uint8_t data);
void DIO_enable_disable_pull_up_port_with_mask(DIO_port_t port,uint8_t data, uint8_t mask);

#endif /* DIO_H_ */