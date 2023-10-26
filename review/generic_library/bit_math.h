/*
 * bit_math.h
 *
 * Created: 23/10/2023 09:11:50 م
 *  Author: Muhammed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,y)	(x |= (1<<y))
#define CLEAR_BIT(x,y)	(x &= ~(1<<y))
#define TOGGLE_BIT(x,y)	(x ^= (1<<y))

#define READ_BIT(x,y)	((x >> y) & 1)

#endif /* BIT_MATH_H_ */