/*
 * KeyPad.c
 *
 *  Created on: Jan 3, 2018
 *      Author: Khalid
 */

#include "KeyPad.h"
#include <avr/io.h>
#include <util/delay.h>

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)
#define read_bit(reg,pin) (reg&(1<<pin))

int store_no;

void KeyPad_Init() // Initialize KeyPad PORTS
{
	DDRA &= 0xE3;    // DDRA PORTS (2->4) Input Confg
	PORTA |= 0x1C;   // PORTS A (2->4) Output 1

	DDRA |= 0xE0;    // DDRA (5->7) Output Confg

}

unsigned int KeyPad()
{

	clear_bit(PORTA,5);
	set_bit(PORTA,6);
	set_bit(PORTA,7);
	if(read_bit(PINA,4)==0)
	{
		store_no=3;
		while(read_bit(PINA,4)==0);
	}
	clear_bit(PORTA,6);
	set_bit(PORTA,5);
	set_bit(PORTA,7);
	if(read_bit(PINA,4)==0)
	{
		store_no=2;
		while(read_bit(PINA,4)==0);
	}
	clear_bit(PORTA,7);
	set_bit(PORTA,6);
	set_bit(PORTA,5);
	if(read_bit(PINA,4)==0)
	{
		store_no=1;
		while(read_bit(PINA,4)==0);
	}
	clear_bit(PORTA,5);
	set_bit(PORTA,6);
	set_bit(PORTA,7);
	if(read_bit(PINA,3)==0)
	{
		store_no=6;
		while(read_bit(PINA,3)==0);
	}
	clear_bit(PORTA,6);
	set_bit(PORTA,5);
	set_bit(PORTA,7);
	if(read_bit(PINA,3)==0)
	{
		store_no=5;
		while(read_bit(PINA,3)==0);
	}
	clear_bit(PORTA,7);
	set_bit(PORTA,6);
	set_bit(PORTA,5);
	if(read_bit(PINA,3)==0)
	{
		store_no=4;
		while(read_bit(PINA,3)==0);
	}
	clear_bit(PORTA,5);
	set_bit(PORTA,6);
	set_bit(PORTA,7);
	if(read_bit(PINA,2)==0)
	{
		store_no=9;
		while(read_bit(PINA,2)==0);
	}
	clear_bit(PORTA,6);
	set_bit(PORTA,5);
	set_bit(PORTA,7);
	if(read_bit(PINA,2)==0)
	{
		store_no=8;
		while(read_bit(PINA,2)==0);
	}
	clear_bit(PORTA,7);
	set_bit(PORTA,6);
	set_bit(PORTA,5);
	if(read_bit(PINA,2)==0)
	{
		store_no=7;
		while(read_bit(PINA,2)==0);
	}
	return store_no;
}

