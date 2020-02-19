/*
 * spi.c
 *
 *  Created on: 17 févr. 2020
 *      Author: Julien
 */


/**************************************
 *			INCLUDES
 *************************************/
#include <stdint.h>
#include <stdbool.h>
#include "spi.h"
#include "LPC176x.h"

/**************************************
 *		PRIVATE DEFENITION
 *************************************/
#define BSY ((SSP1SR & 0x10)>> 4)
/**************************************
 *		PRIVATE DECLARATION
 *************************************/
static uint8_t spi_rw(uint8_t dataByte);
/**************************************
 *		PRIVATE STRUCTURE
 *************************************/


/**************************************
 *		PUBLIC	FUNCTIONS
 *************************************/
	bool spi_init(void){
		static uint8_t init = 0;

		if(init == false){
		__set_PCONP(PCSSP1,1);
		__set_PCLKSEL(PCLK_SSP1, PCLKDIV_4);

		SSP1DR; //read SSP1FIFO

		__set_PINSEL(0,6,2); //SSEL
		__set_PINSEL(0,7,2); //SCK1
		__set_PINSEL(0,8,2); //MISO
		__set_PINSEL(0,9,2); //MOSI

		//NO pull-up nor pull-down
		__set_PINMODE(0,6,2);
		__set_PINMODE(0,7,2);
		__set_PINMODE(0,8,2);
		__set_PINMODE(0,9,2);

		//
		__set_PINOD(0,6,0);
		__set_PINOD(0,7,0);
		__set_PINOD(0,8,0);

		SSP1CPSR = 60;
		SSP1CR0 = 0x0107;
		SSP1CR1 = 2;

		init = 1;
		}
		return true;
	}

	uint8_t spi_8bitTransfert(uint8_t data){
		data = spi_rw(data);
		return data;
	}

	uint16_t spi_16bitTransfert(uint16_t data){
		uint16_t output = 0;
		uint8_t temp[2] = {0};

		temp[1] = (data&0xFF00)>>8;
		temp[0] = (data&0xFF);

		temp[1] = spi_rw(temp[1]);
		temp[0] = spi_rw(temp[0]);

		output  = (temp[1]<<8) + temp[0];

		return output;
	}

	uint32_t spi_32bitTransfert(uint32_t data){
		uint16_t output = 0;
		uint8_t temp[4] = {0};

		temp[3] = (data&0xFF000000)>>24;
		temp[2] = (data&0x00FF0000)>>16;
		temp[1] = (data&0x0000FF00)>>8;
		temp[0] = (data&0x000000FF);

		temp[3] = spi_rw(temp[3]);
		temp[2] = spi_rw(temp[2]);
		temp[1] = spi_rw(temp[1]);
		temp[0] = spi_rw(temp[0]);

		output  = (temp[3] << 24) + (temp[2] << 16) + (temp[1] << 8) + temp[0];
		return output;
	}

	void spi_send80DummyClock(){
		__set_PINSEL(0,6,0);
		FIO0DIR0 = (1 << 6);
		FIO0SET0 = (1 << 6);
		for(int i = 0; i < 10; i++){
			SSP1DR = 0xFF;
			while(BSY){}
		}
		FIO0CLR0 = (1 << 6);
		__set_PINSEL(0,6,2);

	}


/**************************************
 *		PRIVATE FUNCTIONS
 *************************************/
static uint8_t spi_rw(uint8_t dataByte){
    uint8_t dataToReturn = 0;
	SSP1DR = dataByte;
	while(BSY){}
	dataToReturn = SSP1DR;

	return dataToReturn;
}
