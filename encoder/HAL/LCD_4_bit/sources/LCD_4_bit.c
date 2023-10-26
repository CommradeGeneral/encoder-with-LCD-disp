/*
 * LCD_4_bit.c
 *
 * Created: 24/10/2023 08:41:58 م
 *  Author: Muhammed
 */ 

#include "../headers/LCD_4_bit.h"
#include "../../../generic_library/delay.h"

#define LCD_delay_us	2000

void LCD_4_bit_init(const LCD_4_bit_t LCD){
	DIO_set_direction_pin(LCD.D[0],OUTPUT);
	DIO_set_direction_pin(LCD.D[1],OUTPUT);
	DIO_set_direction_pin(LCD.D[2],OUTPUT);
	DIO_set_direction_pin(LCD.D[3],OUTPUT);
	DIO_set_direction_pin(LCD.RS,OUTPUT);
	DIO_set_direction_pin(LCD.EN,OUTPUT);
}

void LCD_4_bit_prg_init(const LCD_4_bit_t LCD){
	_delay_ms(15);
	LCD_4_bit_init(LCD);
	DIO_write_pin(LCD.EN,HIGH);
	DIO_write_pin(LCD.D[0],LOW);
	DIO_write_pin(LCD.D[1],LOW);
	DIO_write_pin(LCD.D[2],LOW);
	DIO_write_pin(LCD.D[3],LOW);
	/*
	DIO_WriteChannel(LCD_RW,STD_Low);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_cmd(0x33);	//
	LCD_cmd(0x32);
	LCD_cmd(0x28);	//function set: two_line
	LCD_cmd(0x06);
	LCD_cmd(0x0C);
	*/
	LCD_4_bit_cmd(LCD,0x33);
	LCD_4_bit_cmd(LCD,0x32);
	LCD_4_bit_cmd(LCD,0x28);
	LCD_4_bit_cmd(LCD,0x06);
	LCD_4_bit_cmd(LCD,0x0C);
	LCD_4_bit_cmd(LCD,0x01);
}

void LCD_4_bit_cmd(const LCD_4_bit_t LCD,uint8_t cmd){
	uint8_t temp_var;
	DIO_write_pin(LCD.RS,LOW);	// select register to command
	
	temp_var =(cmd & 0xF0) >> 4;
	DIO_write_pin(LCD.D[0],(logic_t) (temp_var & 0x01));
	DIO_write_pin(LCD.D[1],(logic_t) ((temp_var & 0x02)>>1));
	DIO_write_pin(LCD.D[2],(logic_t) ((temp_var & 0x04)>>2));
	DIO_write_pin(LCD.D[3],(logic_t) ((temp_var & 0x08)>>3));
	
	// Enable and disable
	
	DIO_write_pin(LCD.EN,HIGH);
	_delay_us(10);
	DIO_write_pin(LCD.EN,LOW);
	_delay_us(LCD_delay_us);
	
	temp_var =  (cmd & 0x0F);
	DIO_write_pin(LCD.D[0],(logic_t) (temp_var & 0x01));
	DIO_write_pin(LCD.D[1],(logic_t) ((temp_var & 0x02)>>1));
	DIO_write_pin(LCD.D[2],(logic_t) ((temp_var & 0x04)>>2));
	DIO_write_pin(LCD.D[3],(logic_t) ((temp_var & 0x08)>>3));
	
	// Enable and disable
	
	DIO_write_pin(LCD.EN,HIGH);
	_delay_us(10);
	DIO_write_pin(LCD.EN,LOW);
	_delay_us(LCD_delay_us);
	
}

void LCD_4_bit_char(const LCD_4_bit_t LCD, uint8_t data){
		uint8_t temp_var;
		DIO_write_pin(LCD.RS,HIGH);	// select register to command
		
		temp_var =(data & 0xF0) >> 4;
		DIO_write_pin(LCD.D[0],(logic_t) (temp_var & 0x01));
		DIO_write_pin(LCD.D[1],(logic_t) ((temp_var & 0x02)>>1));
		DIO_write_pin(LCD.D[2],(logic_t) ((temp_var & 0x04)>>2));
		DIO_write_pin(LCD.D[3],(logic_t) ((temp_var & 0x08)>>3));
		
		// Enable and disable
		
		DIO_write_pin(LCD.EN,HIGH);
		_delay_us(10);
		DIO_write_pin(LCD.EN,LOW);
		_delay_us(LCD_delay_us);
		
		temp_var =  (data & 0x0F);
		DIO_write_pin(LCD.D[0],(logic_t) (temp_var & 0x01));
		DIO_write_pin(LCD.D[1],(logic_t) ((temp_var & 0x02)>>1));
		DIO_write_pin(LCD.D[2],(logic_t) ((temp_var & 0x04)>>2));
		DIO_write_pin(LCD.D[3],(logic_t) ((temp_var & 0x08)>>3));
		
		// Enable and disable
		
		DIO_write_pin(LCD.EN,HIGH);
		_delay_us(10);
		DIO_write_pin(LCD.EN,LOW);
		_delay_us(LCD_delay_us);
}

void LCD_4_bit_string(const LCD_4_bit_t LCD,char str[]){
	uint8_t index = 0;
	while (str[index] != '\0'){
		LCD_4_bit_char(LCD,str[index]);
		index++;
	}
}
