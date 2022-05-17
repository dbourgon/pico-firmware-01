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

#include "menu.h"


uint8_t menu_time( void )
{

    /* write menu to oled display */
    hvAddr_set_page(3, 3);
    hvAddr_set_column(0, 127);
    oled_write_string( "1. Stopwatch" );
    hvAddr_set_page(4, 4);
    hvAddr_set_column(0, 127);
    oled_write_string( "2. Countdown" );
    hvAddr_set_page(5, 5);
    hvAddr_set_column(0, 127);
    oled_write_string( "3. Big Time" );

    while(gpio_get(10)){oled_clock();}

    /* loop until the user makes a choice */
    while(true){
        oled_clock();

        // if button1 is high, load stopwatch function, then break out of loop
        if( gpio_get(10) == true ) {
            stopwatch();
            break;
        }
        // if button2 is high, load countdown function, then break out of loop
        if( gpio_get(11) == true ) {
            countdown();
            break;
        }
        // if button3 is high, load big time function, then break out of loop
        if( gpio_get(12) == true ) {
            bigtime();
            break;
        }

    }

    return 0;

}

uint8_t menu_config( void )
{


    return 0;

}

uint8_t menu_tools( void )
{


    return 0;

}

uint8_t menu_main( void )
{

    hvAddr_set_page(3, 3);
    hvAddr_set_column(0, 127);
    oled_write_string( "1. Time" );
    hvAddr_set_page(4, 4);
    hvAddr_set_column(0, 127);
    oled_write_string( "2. Tools" );
    hvAddr_set_page(5, 5);
    hvAddr_set_column(0, 127);
    oled_write_string( "3. Config" );

    return 0;

}
