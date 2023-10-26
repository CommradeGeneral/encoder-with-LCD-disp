/*
* rotary_encoder.c
*
* Created: 26/10/2023 08:30:05 ص
*  Author: Muhammed
*/
#include "../headers/rotary_encoder.h"

static volatile uint32_t pulses_counter[3];

static void encoder_count_up_0 (void);
static void encoder_count_up_1 (void);
static void encoder_count_up_2 (void);
static void encoder_count_up_0_no_double (void);
static void encoder_count_up_1_no_double (void);
static void encoder_count_up_2_no_double (void);

static void encoder_count_down_0 (void);
static void encoder_count_down_1 (void);
static void encoder_count_down_2 (void);
static void encoder_count_down_0_no_double (void);
static void encoder_count_down_1_no_double (void);
static void encoder_count_down_2_no_double (void);


static void (*encoder_count_up[3])(void) = {
	encoder_count_up_0,
	encoder_count_up_1,
	encoder_count_up_2
};

static void (*encoder_count_up_no_double[3])(void) = {
	encoder_count_up_0_no_double,
	encoder_count_up_1_no_double,
	encoder_count_up_2_no_double
};

static void (*encoder_count_down[3])(void) = {
	encoder_count_down_0,
	encoder_count_down_1,
	encoder_count_down_2
};

static void (*encoder_count_down_no_double[3])(void) = {
	encoder_count_down_0_no_double,
	encoder_count_down_1_no_double,
	encoder_count_down_2_no_double
};



void encoder_init(rotary_encoder_t encoder){
	GINT_enable_global_interrupt();
	INTx_init(encoder.INTx_pol0_init,INTx_FALLING_EDGE,ENABLE);
	INTx_init(encoder.INTx_pol1_init,INTx_FALLING_EDGE,ENABLE);
	if (encoder.is_doubled) {
		INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_up[encoder.ser_no]);
		INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_down[encoder.ser_no]);
		} else {
		INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_up_no_double[encoder.ser_no]);
		INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_down_no_double[encoder.ser_no]);
	}

}

void encoder_reverse_poles(rotary_encoder_t encoder){
	static uint8_t pole = 0;
	pole = (pole+1) %2;
	if (pole == 0) {
		if (encoder.is_doubled) {
			INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_up[encoder.ser_no]);
			INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_down[encoder.ser_no]);
			} else {
			INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_up_no_double[encoder.ser_no]);
			INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_down_no_double[encoder.ser_no]);
		}
		} else if (pole == 1) {
		if (encoder.is_doubled) {
			INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_up[encoder.ser_no]);
			INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_down[encoder.ser_no]);
			} else {
			INTx_ISR_callback(encoder.INTx_pol1_init,encoder_count_up_no_double[encoder.ser_no]);
			INTx_ISR_callback(encoder.INTx_pol0_init,encoder_count_down_no_double[encoder.ser_no]);
		}
	}
}

int32_t encoder_get_pulses(rotary_encoder_t encoder){
	return pulses_counter[encoder.ser_no];
}

// counting up for all functions
void encoder_count_up_0(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[0]++;
		} else {
		pulses_counter[0]--;
	}
}

void encoder_count_up_1(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[1]++;
		} else {
		pulses_counter[1]--;
	}
}

void encoder_count_up_2(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[2]++;
		} else {
		pulses_counter[2]--;
	}
}

void encoder_count_up_0_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[0]++;
		} else {
	}
}

void encoder_count_up_1_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[1]++;
		} else {
	}
}

void encoder_count_up_2_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D3))){
		pulses_counter[2]++;
		} else {
	}
}

// counting up for all functions


void encoder_count_down_0(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[0]--;
		} else {
		pulses_counter[0]++;
	}
}

void encoder_count_down_1(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[1]--;
		} else {
		pulses_counter[1]++;
	}
}

void encoder_count_down_2(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[2]--;
		} else {
		pulses_counter[2]++;
	}
}

void encoder_count_down_0_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[0]--;
		} else {
	}
}

void encoder_count_down_1_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[1]--;
		} else {
	}
}

void encoder_count_down_2_no_double(void){
	if (!(DIO_read_pin(DIO_pin_D2))){
		pulses_counter[2]--;
		} else {
	}
}