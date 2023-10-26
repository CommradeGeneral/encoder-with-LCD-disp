/*
* EXT_INT_REG.h
*
* Created: 25/10/2023 03:52:07 م
*  Author: Muhammed
*/


#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#include "../../../generic_library/STD_data_types.h"

#define INTx_LOW_LEVEL		0
#define INTx_ON_CHANGE		1
#define INTx_FALLING_EDGE	2
#define INTx_RISING_EDGE	3

#define INT0_pin		DIO_pin_D2
#define INT1_pin		DIO_pin_D3
#define INT2_pin		DIO_pin_B2


#define MCUCR	(*(MCUCRbits_t*)0x55)
#define MCUCSR	(*(MCUCSRbits_t*)0x54)
#define GICR	(*(GICRbits_t*)0x5B)
#define GIFR	(*(GIFRbits_t*)0x5A)

typedef union {
	struct {
		uint8_t ISC00:1;
		uint8_t ISC01:1;
		uint8_t ISC10:1;
		uint8_t ISC11:1;
	};
	struct {
		uint8_t INT0_sense_CTRL:2;
		uint8_t INT1_sense_CTRL:2;
	};
} MCUCRbits_t;

typedef union {
	struct {
		uint8_t :6;
		uint8_t ISC2:1;
		uint8_t :1;
	};
	struct {
		uint8_t :5;
		uint8_t INT2_sense_CTRL:2;
		uint8_t :1;
	};
} MCUCSRbits_t;

typedef struct {
	uint8_t :5;
	uint8_t INT2:1;
	uint8_t INT0:1;
	uint8_t INT1:1;
} GICRbits_t;

typedef struct {
	uint8_t :5;
	uint8_t INTF2:1;
	uint8_t INTF0:1;
	uint8_t INTF1:1;
} GIFRbits_t;



#endif /* EXT_INT_REG_H_ */