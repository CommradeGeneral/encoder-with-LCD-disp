/*
 * rotary_encoder.h
 *
 * Created: 26/10/2023 08:21:57 ص
 *  Author: Muhammed
 */ 


#ifndef ROTARY_ENCODER_H_
#define ROTARY_ENCODER_H_

#include "../../../MCAL/DIO/headers/DIO.h"
#include "../../../MCAL/EXT_INT/headers/EXT_INT.h"
#include "../../../MCAL/GINT/headers/GINT.h"

#define POLARITY_FORWARD	0
#define POLARITY_REVERSE	1


typedef struct {
	uint8_t polarity_init:1;
	uint8_t INTx_pol0_init:2;
	uint8_t INTx_pol1_init:2;
	uint8_t is_doubled:1;
	uint8_t ser_no;
	uint16_t ppr;
	} rotary_encoder_t;
	
int32_t encoder_get_pulses(rotary_encoder_t encoder);
void encoder_init(rotary_encoder_t);
void encoder_reverse_poles(rotary_encoder_t);

#endif /* ROTARY_ENCODER_H_ */