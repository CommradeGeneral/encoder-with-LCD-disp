/*
 * GINT.h
 *
 * Created: 25/10/2023 03:27:31 م
 *  Author: Muhammed
 */ 


#ifndef GINT_H_
#define GINT_H_

#include "../../../generic_library/bit_math.h"
#include "../../../generic_library/STD_data_types.h"

#define SREG_INT			(*(volatile uint8_t*) 0x5F)
#define GINT_BIT_MASK		7

void GINT_enable_global_interrupt(void);
void GINT_disable_global_interrupt(void);
#endif /* GINT_H_ */