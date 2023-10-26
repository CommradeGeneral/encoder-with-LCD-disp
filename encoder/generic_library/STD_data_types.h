/*
 * STD_data_types.h
 *
 * Created: 23/10/2023 09:06:54 م
 *  Author: Muhammed
 */ 


#ifndef STD_DATA_TYPES_H_
#define STD_DATA_TYPES_H_

#include <stdint.h>


/*
typedef	unsigned char		uint8_t;
typedef	unsigned short		uint16_t;
typedef	unsigned long		uint32_t;
typedef	unsigned long long	uint64_t;

typedef	signed char			int8_t;
typedef	signed short		int16_t;
typedef	signed long			int32_t;
typedef	signed long long	int64_t;


*/ 

#define		NULL	((void*)0x00)
#define TRUE	1
#define FALSE	0

typedef enum {
	LOW		= 0,
	HIGH
} logic_t;

typedef enum {
	DISABLE = 0,
	ENABLE
} active_t;


#endif /* STD_DATA_TYPES_H_ */