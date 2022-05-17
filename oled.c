/*
* Copyright (c) 2022 David Bourgon
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*/

// 1: 0xae #set display off
// 2: 0xa6 #set display normal (non-inverted)

#include "oled.h"




/*
* Send a single byte command to the OLED display.
*/
void oled_cmd( uint8_t cmd )
{
    uint8_t buf[2] = {0x80, cmd};
    i2c_write_blocking(i2c_default, 0x3C, buf, 2, false);
}

/*
* Write a single byte of data to the OLED display buffer
*/
void oled_write( uint8_t data )
{
    uint8_t buf[2] = {0x40, data};
    i2c_write_blocking(i2c_default, 0x3c, buf, 2, false);
}

/*
* Write an 8-byte character to the screen
*/
void oled_write_char( const uint8_t chardata[8] )
{
    for( uint8_t i = 0; i < 8; i++ )
    {
        oled_write( chardata[i] );
    }
}

/*
 * Write a string of character to the screen.
 * Limited to 16 characters, max per line of oled.
 */
void oled_write_string( char str[16] )
{
    for( uint8_t i = 0; i < 16; i++ ) {
        if( str[i] == '\0' ){
            break;
        } else {
            oled_write_char(oled_font01[(uint)str[i]]);
        }
    }
}

/*
 * Convert number to string then
 * print characters to screen.
 */
void oled_write_number( uint num )
{
    char buf[16];
    snprintf(buf, sizeof(buf), "%d", (num % 35565));
    oled_write_string(buf);
}

/*
* Initialize the OLED display
*/
void oled_init( void )
{
        uint8_t *init_seq = get_init_seq();

        for( uint8_t i = 0; i < 25; i++ ) {
            oled_cmd(init_seq[i]);
        }
}

/*
* Reset the display pointer to 0
*/
void oled_reset( void )
{
    uint8_t reset_seq[6] = {    0x21,
        0x00,
        0xff,
        0x22,
        0x00,
        0x07 };

        for(int i = 0; i < 6; i++) {
            oled_cmd(reset_seq[i]);
        }
}

/*
* Reset display and set all 1024 bytes in the display buffer
* to 0x00
*/
void oled_clear( void )
{
    oled_reset();
    for( int i = 0; i < 1024; i++ ){
        oled_write(0x00);
    }
}

/*
 *
 * *************************************/
void oled_setmemaddr_mode(uint8_t mode)
{
    uint8_t cmd[2] = {0x20, mode};
    for( int i = 0; i < sizeof(cmd); i++) {
        oled_cmd(cmd[i]);
    }
}

void pgAddr_set_lower_column_start(uint8_t addr)
{
    if ( addr > 0x0F ) {
        oled_cmd(0x00);
    } else {
        oled_cmd(addr);
    }
}

void pgAddr_set_higher_column_start(uint8_t addr)
{
    if ( addr < 0x10 || addr > 0x1F ) {
        oled_cmd(0x10);
    } else {
        oled_cmd(addr);
    }
}

void pgAddr_set_page_start(uint8_t addr)
{
    if ( addr < 0xB0 || addr > 0xB7 ) {
        oled_cmd(0xB0);
    } else {
        oled_cmd(addr);
    }
}

void hvAddr_set_column(uint8_t start_addr, uint8_t end_addr)
{
    uint8_t cmd[3];
    if ( start_addr > 0x7F ){
        cmd[0] = 0x21;
        cmd[1] = 0x00;
    } else {
        cmd[0] = 0x21;
        cmd[1] = start_addr;
    }

    if ( end_addr > 0x7F || end_addr < start_addr ) {
        cmd[2] = 0x00;
    } else {
        cmd[2] = end_addr;
    }

    for( int i=0; i < sizeof(cmd); i++ ) {
        oled_cmd(cmd[i]);
    }
}

void hvAddr_set_page(uint8_t start_addr, uint8_t end_addr)
{
    uint8_t cmd[3];
    if ( start_addr > 0x07 ) {
        cmd[0] = 0x22;
        cmd[1] = 0x00;
    } else {
        cmd[0] = 0x22;
        cmd[1] = start_addr;
    }

    if ( end_addr > 0x07 || end_addr < start_addr ) {
        cmd[2] = 0x00;
    } else {
        cmd[2] = end_addr;
    }

    for( int i=0; i < sizeof(cmd); i++ ) {
        oled_cmd(cmd[i]);
    }
}








