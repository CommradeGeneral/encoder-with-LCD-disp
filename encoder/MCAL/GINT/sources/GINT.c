/*
 * CFile1.c
 *
 * Created: 25/10/2023 03:27:58 م
 *  Author: Muhammed
 */ 

#include "../headers/GINT.h"

void GINT_enable_global_interrupt(void){
	SET_BIT(SREG_INT,GINT_BIT_MASK);
}

void GINT_disable_global_interrupt(void){
	CLEAR_BIT(SREG_INT,GINT_BIT_MASK);
}