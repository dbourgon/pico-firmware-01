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

#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ssd1306_font01.h"
#include "clock.h"
#include "oled.h"

/*
* Configure the Real Time Clock
*/
void rtc_config( void )
{
    datetime_t t = {
    .year = 2022,
    .month = 04,
    .day = 20,
    .dotw = 3,
    .hour = 00,
    .min = 00,
    .sec = 00
    };

    rtc_init();
    rtc_set_datetime(&t);
}

/*
* Update the datetime_t structure.
* Values are incremented by the value passed
* to the function.
********************************************/
void update_datetime( int h, int m, int s )
{
    datetime_t t;
    rtc_get_datetime(&t);
    /* Does not automatically wrap to zero.
     * Must check and manually reset.
     **************************************/
    if ( t.hour == 23 ) {
        t.hour = 0;
    } else {
        t.hour += h;
    }

    if ( t.min == 59 ) {
        t.min = 0;
    } else {
        t.min += m;
    }

    if ( t.sec == 59 ) {
        t.sec = 0;
    } else {
        t.sec += s;
    }

    rtc_set_datetime(&t);
}

bool rtc_compare_time( int h, int m, int s )
{
    datetime_t t;
    rtc_get_datetime(&t);
    bool hb = false;
    bool mb = false;
    bool sb = false;

    if( h <= ((int)t.hour) ) {
        hb = true;
    }
    if( m <= ((int)t.min) ) {
        mb = true;
    }
    if( s <= ((int)t.sec) ) {
        sb = true;
    }
    if( hb && mb && sb ) {
        return true;
    }
    return false;
}

/*
* Display RTC data
*/
void oled_clock( void )
{
    char dtbuf[256];
    char *dtstr = &dtbuf[0];
    datetime_t t;

    hvAddr_set_page(0x00, 0x00);
    hvAddr_set_column(0x20, 0x7f);

    rtc_get_datetime(&t);
    uint hour = t.hour;
    uint min = t.min;
    uint sec = t.sec;

    sprintf(dtstr, "%d", hour);
    if( hour < 10 ) {
        oled_write_char(oled_font01['0']);
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
    } else {
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
        oled_write_char(oled_font01[(uint)dtbuf[1]]);
    }
    oled_write_char(oled_font01[':']);

    sprintf(dtstr, "%d", min);
    if( min < 10 ) {
        oled_write_char(oled_font01['0']);
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
    } else {
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
        oled_write_char(oled_font01[(uint)dtbuf[1]]);
    }
    oled_write_char(oled_font01[':']);

    sprintf(dtstr, "%d", sec);
    if( sec < 10 ) {
        oled_write_char(oled_font01['0']);
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
    } else {
        oled_write_char(oled_font01[(uint)dtbuf[0]]);
        oled_write_char(oled_font01[(uint)dtbuf[1]]);
    }
}

void stopwatch( void ){}
void countdown( void ){}
void bigtime( void ){}

