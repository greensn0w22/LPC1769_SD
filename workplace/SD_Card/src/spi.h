/*
 * spi.h
 *
 *  Created on: 17 févr. 2020
 *      Author: Julien
 */

#ifndef SPI_H_
#define SPI_H_

/**************************************
 *		INCLUDES
 *************************************/
#include <stdint.h>
#include <stdbool.h>
#include "LPC176x.h"

/**************************************
 *		PUBLIC DEFENITIONS
 *************************************/

/**************************************
 * 		SPI FUNCTIONS
 *************************************/

	bool spi_init(void);

	uint8_t 	spi_8bitTransfert(uint8_t data);

	uint16_t 	spi_16bitTransfert(uint16_t data);

	uint32_t 	spi_32bitTransfert(uint32_t data);

	void 		spi_send80DummyClock(void);







#endif /* SPI_H_ */
