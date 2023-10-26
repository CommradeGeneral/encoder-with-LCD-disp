/*
 * LCD_4_bit.h
 *
 * Created: 24/10/2023 08:41:41 م
 *  Author: Muhammed
 */ 


#ifndef LCD_4_BIT_H_
#define LCD_4_BIT_H_

#include "../../../MCAL/DIO/headers/DIO.h"



typedef struct {
		DIO_pin_number_t D[4];
		DIO_pin_number_t RS;
		DIO_pin_number_t EN;
	}LCD_4_bit_t;
	
void LCD_4_bit_init(const LCD_4_bit_t LCD);
void LCD_4_bit_cmd(const LCD_4_bit_t LCD,uint8_t cmd);
void LCD_4_bit_char(const LCD_4_bit_t LCD, uint8_t data);
void LCD_4_bit_prg_init(const LCD_4_bit_t LCD);
void LCD_4_bit_string(const LCD_4_bit_t LCD, char str[]);


#endif /* LCD_4_BIT_H_ */