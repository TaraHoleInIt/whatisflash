#include <avr/io.h>
#include <util/delay.h>
#include "mainapp.h"

#if defined Config_SPI_SW

#define __SPI_TXBit( Data, Bit ) { \
    Config_SPI_PORT = ( Data & _BV( Bit ) ) ? Config_SPI_PORT | Config_SPI_DO : Config_SPI_PORT & ~Config_SPI_DO; \
    Config_SPI_PORT |= Config_SPI_SCK; \
    Config_SPI_PORT &= ~Config_SPI_SCK; \
}

void SPI_SelectFlash( void ) {
    Config_SPI_PORT &= ~Config_Flash_CS;
}

void SPI_DeselectFlash( void ) {
    Config_SPI_PORT |= Config_Flash_CS;
}

void SPI_SelectDisplay( void ) {
#if defined Config_LCD_CS
    Config_SPI_PORT &= ~Config_LCD_CS;
#endif
}

void SPI_DeselectDisplay( void ) {
#if defined Config_LCD_CS
    Config_SPI_PORT |= Config_LCD_CS;
#endif
}

void SPI_TX( const uint8_t Data ) {
    __SPI_TXBit( Data, 7 );
    __SPI_TXBit( Data, 6 );
    __SPI_TXBit( Data, 5 );
    __SPI_TXBit( Data, 4 );
    __SPI_TXBit( Data, 3 );
    __SPI_TXBit( Data, 2 );
    __SPI_TXBit( Data, 1 );
    __SPI_TXBit( Data, 0 );

    // Make clock line idle again
    Config_SPI_PORT &= ~Config_SPI_SCK;
}

void SPI_Init( void ) {
    // Set needed lines as output
    Config_SPI_DDR = Config_SPI_DO | Config_SPI_SCK | Config_Flash_CS;

    // Default to SCK, DO low and both CS lines high
    Config_SPI_PORT = Config_Flash_CS;

#if defined Config_LCD_CS
    Config_SPI_DDR |= Config_LCD_CS;
    Config_SPI_PORT |= Config_Flash_CS;
#endif
}

#endif

