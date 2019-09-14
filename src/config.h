#ifndef _CONFIG_H_
#define _CONFIG_H_

#define Config_SPI_USI
//#define Config_SPI_HW
//#define Config_SPI_SW

#define Config_FrameDelay 40

#define Config_FrameSize 1024
#define Config_FrameCount 7
#define Config_InitSize 40

#define Config_SPI_PORT PORTB
#define Config_SPI_DDR DDRB

#define Config_SPI_DO _BV( 1 )
#define Config_SPI_SCK _BV( 2 )

#define Config_LCD_CS _BV( 3 )
#define Config_Flash_CS _BV( 4 )

#endif
