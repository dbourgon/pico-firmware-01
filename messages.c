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

#include "messages.h"
#include "oled.h"

struct iconstatus {
        bool timer;
        bool warn;
} istatus = {false, false};


void show_icons( bool enabled )
{
    if( enabled ) {
        msgset_timer_icon(istatus.timer);
        msgset_warn_icon(istatus.warn);
    }
}

void msgset_timer_icon( bool set )
{
    uint8_t icon[8] = TIMER_ICON;

    hvAddr_set_page(0x01, 0x01);
    hvAddr_set_column(0x00, 0x07);

    if( set == true ) {
        oled_write_char(icon);
    } else if( set == false ) {
        oled_write_char(oled_font01[' ']);
    }

    oled_reset();
}

void msgset_warn_icon( bool set )
{
    uint8_t icon[8] = WARN_ICON;

    hvAddr_set_page(0x01, 0x01);
    hvAddr_set_column(0x10, 0x17);


    if( set == true ) {
        oled_write_char(icon);
    } else if( set == false ) {
        oled_write_char(oled_font01[' ']);
    }

    oled_reset();
}

