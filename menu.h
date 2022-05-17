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
#include <stdlib.h>
#include <stdint.h>

#include "oled.h"
#include "clock.h"
#include "messages.h"
#include "irq.h"
#include "oledll.h"

uint8_t menu_time( void );
uint8_t menu_config( void );
uint8_t menu_tools( void );
uint8_t menu_main( void );
