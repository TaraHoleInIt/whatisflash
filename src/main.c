#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>
#include "mainapp.h"

void FlashRead( uint32_t Address, size_t Size ) {
    size_t i = 0;

    SPI_SelectFlash( );
        SPI_TX( 0x03 ); // flash read
        SPI_TX( ( Address >> 16 ) & 0xFF );
        SPI_TX( ( Address >> 8 ) & 0xFF );
        SPI_TX( Address & 0xFF );

        SPI_SelectDisplay( );
            for ( i = 0; i < Size; i++ ) {
#if defined Config_SPI_SW
                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;

                Config_SPI_PORT |= Config_SPI_SCK;
                Config_SPI_PORT &= ~Config_SPI_SCK;
#elif defined Config_SPI_USI
                blah
#else
                SPI_TX( 0x00 ); // flash DI->display DO pump
#endif
            }
        SPI_DeselectDisplay( );
    SPI_DeselectFlash( );
}

int main( void ) {
    uint32_t i = 0;

    SPI_Init( );

    // While DC is low pump out the LCD init commands from flash
    FlashRead( 0, Config_InitSize );

    // Wait for DC to go high and put the lcd in data mode
    _delay_ms( 500 );

    while ( 1 ) {
        for ( i = 0; i < Config_FrameCount; i++ ) {
            FlashRead( Config_InitSize + 4 + ( i * Config_FrameSize ), Config_FrameSize - 4 );

#if defined Config_FrameDelay
            _delay_ms( Config_FrameDelay );
#endif
        }
    }

    return 0;
}
