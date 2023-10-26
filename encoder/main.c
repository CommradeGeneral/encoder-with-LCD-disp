/*
* review.c
*
* Created: 23/10/2023 08:56:24
* Author : Muhammad
*/

//#include <avr/io.h>
#include "generic_library/delay.h"
#include "HAL/relay/headers/relay.h"
#include "HAL/LCD_4_bit/headers/LCD_4_bit.h"
#include "HAL/LCD_8_bit/headers/LCD_8_bit.h"
#include "HAL/rotary_encoder/headers/rotary_encoder.h"
#include <stdio.h>
#include <stdlib.h>

int8_t kk;
int32_t acc;
uint8_t acc2;
int32_t memory = 150;
uint8_t memory2 = 1;

int32_t distances[6] = {
	0,
	1910*1,
	1910*2,
	1910*3,
	1910*4,
	1910*5
};


int32_t selectors[10] = {
	//1432 - 620,
	0 + 300,
	1920 - 300,
	1920 + 300,
	1910*2 - 300,
	1910*2 + 300,
	1910*3 - 300,
	1910*3 + 300,
	1910*4 - 300,
	1910*4 + 300,
	1910*5 - 300
};
uint8_t floor_calc(int32_t list[],uint8_t num_of_floors,int32_t current_distance);
void floor_calc_2(int32_t list[],uint8_t num_of_floors,int32_t current_distance);

const rotary_encoder_t encoder0 = {
	.INTx_pol0_init = 0,
	.INTx_pol1_init = 1,
	.ser_no = 0,
	.is_doubled = FALSE
};


const LCD_4_bit_t LCD1 = {
	.RS		= DIO_pin_C0,
	.EN		= DIO_pin_C2,
	.D[0]	= DIO_pin_D4,
	.D[1]	= DIO_pin_D5,
	.D[2]	= DIO_pin_D6,
	.D[3]	= DIO_pin_D7
};

const relay_t relay1 = {
	.pin_number = DIO_pin_A0,
	.state_init = HIGH
};

const relay_t relay2 = {
	.pin_number = DIO_pin_A1,
	.state_init = HIGH
};


char buff[16];

int main(void)
{
	encoder_init(encoder0);
	DIO_set_direction_pin(DIO_pin_B7,INPUT);
	DIO_enable_disable_pull_up_pin(DIO_pin_B7,ENABLE);
	LCD_4_bit_prg_init(LCD1);
	relay_init(relay1);
	relay_init(relay2);
	while (1)
	{
		acc2 = floor_calc(distances,6,encoder_get_pulses(encoder0));
		floor_calc_2(selectors,10,encoder_get_pulses(encoder0));
		acc = encoder_get_pulses(encoder0);
		if (abs(memory - acc)>2){
			memory = (acc);
			LCD_4_bit_cmd(LCD1,0x01);
			sprintf(buff, "d = %ld",acc);
			LCD_4_bit_string(LCD1,buff);
			LCD_4_bit_cmd(LCD1,0x80 + 0x40);
			sprintf(buff, "floor = %d", acc2);
			LCD_4_bit_string(LCD1,buff);
		}
		
		
	}
	
	
}

uint8_t floor_calc(int32_t list[],uint8_t num_of_floors,int32_t current_distance){
	logic_t temp_floor = HIGH;
	static uint8_t temp_floor_2 = 0;
	for (uint8_t k=0;k<num_of_floors;k++){
		if (abs(list[k] - current_distance) < 72) {
			temp_floor = LOW;
			temp_floor_2 = k;
			break;
		} else {
			
		}
	}
	relay_set_logic(relay1,temp_floor);
	return temp_floor_2;
}

void floor_calc_2(int32_t list[],uint8_t num_of_floors,int32_t current_distance){
	logic_t temp_floor = HIGH;
	for (uint8_t k=0;k<num_of_floors;k++){
		if (abs(list[k] - current_distance) < 140) {
			temp_floor = LOW;
			break;
			} else {
			
		}
	}
	relay_set_logic(relay2,temp_floor);
}

/*
ISR(INT0_vect){
if (!(DIO_read_pin(DIO_pin_D3))){
kk++;
acc++;
} else {
kk--;
acc++;
}
}


ISR(INT1_vect){
if (!(DIO_read_pin(DIO_pin_D2))){
kk--;
} else {

kk++;
}
acc++;
}
*/

