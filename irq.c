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

#include <stdio.h>
#include <stdlib.h>

#include "irq.h"
#include "oled.h"
#include "clock.h"
#include "menu.h"


void gpcallback( uint gpio, uint32_t events )
{
    switch(gpio)
    {
        case 10:    // Button 1
            menu_time();
            break;

        case 11:    // Button 2
            menu_tools();
            break;

        case 12:    // Button 3
            menu_config();
            break;


        default:    // ERROR
            break;

    }
}
