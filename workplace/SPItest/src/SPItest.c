/*
===============================================================================
 Name        : SPItest.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


#include "board.h"
#include <cr_section_macros.h>
#include "spi.h"

static void CoreInit(void){
    SystemCoreClockUpdate();
    Board_Init();
    Board_LED_Set(0, true);
}


int main(void) {
	CoreInit();
    volatile static int i = 0 ;

    spi_init();


    while(1) {

    }
    return 0 ;
}



