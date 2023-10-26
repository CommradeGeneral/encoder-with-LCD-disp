/*
 * IncFile1.h
 *
 * Created: 25/10/2023 03:31:59 م
 *  Author: Muhammed
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "../../../generic_library/bit_math.h"
#include "EXT_INT_REG.h"
#include "../../DIO/headers/DIO.h"



void INTx_init(uint8_t INTx,uint8_t sense_control,active_t int_enable);
void INTx_set_sense_control(uint8_t INTx,uint8_t sense_control);
void INTx_interrupt_enable(uint8_t INTx);
void INTx_interrupt_disable(uint8_t INTx);
void INTx_ISR_callback(uint8_t INTx,void (*callback)(void));

#endif /* INCFILE1_H_ */