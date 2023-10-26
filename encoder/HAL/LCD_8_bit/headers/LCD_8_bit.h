/*
 * LCD_8_bit.h
 *
 * Created: 24/10/2023 10:43:37 م
 *  Author: Muhammed
 */ 


#ifndef LCD_8_BIT_H_
#define LCD_8_BIT_H_


#include "../../../MCAL/DIO/headers/DIO.h"



typedef struct {
	DIO_pin_number_t D[8];
	DIO_pin_number_t RS;
	DIO_pin_number_t EN;
}LCD_8_bit_t;

void LCD_8_bit_init(const LCD_8_bit_t LCD);
void LCD_8_bit_cmd(const LCD_8_bit_t LCD,uint8_t cmd);
void LCD_8_bit_char(const LCD_8_bit_t LCD, uint8_t data);
void LCD_8_bit_prg_init(const LCD_8_bit_t LCD);
void LCD_8_bit_string(const LCD_8_bit_t LCD, char str[]);




#endif /* LCD_8_BIT_H_ */