/*
 * LCD_8_bits.c
 *
 * Created: 24/10/2023 10:43:19 م
 *  Author: Muhammed
 */ 
#include "../headers/LCD_8_bit.h"
#include "../../../generic_library/delay.h"

#define LCD_delay_us	100


void LCD_8_bit_init(const LCD_8_bit_t LCD){
	DIO_set_direction_pin(LCD.D[0],OUTPUT);
	DIO_set_direction_pin(LCD.D[1],OUTPUT);
	DIO_set_direction_pin(LCD.D[2],OUTPUT);
	DIO_set_direction_pin(LCD.D[3],OUTPUT);
	DIO_set_direction_pin(LCD.D[4],OUTPUT);
	DIO_set_direction_pin(LCD.D[5],OUTPUT);
	DIO_set_direction_pin(LCD.D[6],OUTPUT);
	DIO_set_direction_pin(LCD.D[7],OUTPUT);
	DIO_set_direction_pin(LCD.RS,OUTPUT);
	DIO_set_direction_pin(LCD.EN,OUTPUT);
}

void LCD_8_bit_prg_init(const LCD_8_bit_t LCD){
	_delay_ms(20);
	LCD_8_bit_init(LCD);
	LCD_8_bit_cmd(LCD,0b00111100);	//function 1
	LCD_8_bit_cmd(LCD,0b00001111);
	LCD_8_bit_cmd(LCD,0b00000110);
	LCD_8_bit_cmd(LCD,0b00000001);
}

void LCD_8_bit_cmd(const LCD_8_bit_t LCD,uint8_t cmd){
	DIO_write_pin(LCD.RS,LOW);	// select register to command
	
	DIO_write_pin(LCD.D[0],(logic_t) (cmd & 0x01));
	DIO_write_pin(LCD.D[1],(logic_t) ((cmd & 0x02)>>1));
	DIO_write_pin(LCD.D[2],(logic_t) ((cmd & 0x04)>>2));
	DIO_write_pin(LCD.D[3],(logic_t) ((cmd & 0x08)>>3));
	DIO_write_pin(LCD.D[4],(logic_t) ((cmd & 0x10)>>4));
	DIO_write_pin(LCD.D[5],(logic_t) ((cmd & 0x20)>>5));
	DIO_write_pin(LCD.D[6],(logic_t) ((cmd & 0x40)>>6));
	DIO_write_pin(LCD.D[7],(logic_t) ((cmd & 0x80)>>7));
	// Enable and disable
	
	DIO_write_pin(LCD.EN,HIGH);
	_delay_us(10);
	DIO_write_pin(LCD.EN,LOW);
	_delay_us(LCD_delay_us);
		
}

void LCD_8_bit_char(const LCD_8_bit_t LCD,uint8_t data){
	DIO_write_pin(LCD.RS,HIGH);	// select register to command
	
	DIO_write_pin(LCD.D[0],(logic_t) (data & 0x01));
	DIO_write_pin(LCD.D[1],(logic_t) ((data & 0x02)>>1));
	DIO_write_pin(LCD.D[2],(logic_t) ((data & 0x04)>>2));
	DIO_write_pin(LCD.D[3],(logic_t) ((data & 0x08)>>3));
	DIO_write_pin(LCD.D[4],(logic_t) ((data & 0x10)>>4));
	DIO_write_pin(LCD.D[5],(logic_t) ((data & 0x20)>>5));
	DIO_write_pin(LCD.D[6],(logic_t) ((data & 0x40)>>6));
	DIO_write_pin(LCD.D[7],(logic_t) ((data & 0x80)>>7));
	// Enable and disable
	
	DIO_write_pin(LCD.EN,HIGH);
	_delay_us(10);
	DIO_write_pin(LCD.EN,LOW);
	_delay_us(LCD_delay_us);
	
}

void LCD_8_bit_string(const LCD_8_bit_t LCD,char str[]){
	uint8_t index = 0;
	while (str[index] != '\0'){
		LCD_8_bit_char(LCD,str[index]);
		index++;
	}
}
