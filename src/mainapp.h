#ifndef _MAINAPP_H_
#define _MAINAPP_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "config.h"

void SPI_Init( void );
void SPI_TX( const uint8_t Data );

void SPI_SelectFlash( void );
void SPI_DeselectFlash( void );

void SPI_SelectDisplay( void );
void SPI_DeselectDisplay( void ); 

#endif
