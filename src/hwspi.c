#include <avr/io.h>
#include "mainapp.h"

#if defined Config_SPI_HW

void SPI_Init( void ) {
    Config_SPI_DDR = Config_Flash_CS | Config_LCD_CS | Config_SPI_DO | Config_SPI_SCK;
    Config_SPI_PORT = Config_Flash_CS | Config_LCD_CS;
}

void SPI_TX( const unsigned char Data ) {
}

void SPI_SelectFlash( void ) {
    Config_SPI_PORT &= ~Config_Flash_CS;
}

void SPI_DeselectFlash( void ) {
    Config_SPI_PORT |= Config_Flash_CS;
}

void SPI_SelectDisplay( void ) {
    Config_SPI_PORT &= ~Config_LCD_CS;
}

void SPI_DeselectDisplay( void ) {
    Config_SPI_PORT |= Config_LCD_CS;
}

#endif
