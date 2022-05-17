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

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306_font01.h"
#include "oledll.h"

void oled_cmd( uint8_t cmd );
void oled_write( uint8_t data );
void oled_write_char( const uint8_t chardata[8] );
void oled_write_string( char str[16] );
void oled_write_number( uint num );
void oled_init( void );
void oled_reset( void );
void oled_clear( void );

#define MEMADDRMODE_HORIZ   0x00
#define MEMADDRMODE_VERT    0x01
#define MEMADDRMODE_PAGE    0x02
void oled_setmemaddr_mode(uint8_t mode);


void pgAddr_set_lower_column_start(uint8_t addr);
void pgAddr_set_higher_column_start(uint8_t addr);
void pgAddr_set_page_start(uint8_t addr);

void hvAddr_set_column(uint8_t start_addr, uint8_t end_addr);
void hvAddr_set_page(uint8_t start_addr, uint8_t end_addr);
