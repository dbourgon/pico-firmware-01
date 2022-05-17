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
#include <stdbool.h>
#include <stdint.h>

#define TIMER_ICON {0x00,0x3a,0x44,0x92,0x9e,0x82,0x44,0x3a}
#define WARN_ICON {0x00,0xfe,0xfe,0xfe,0xa2,0xfe,0xfe,0xfe}

#define FOOTER_FILL_LEFT {0x00,0x00,0x00,0x00,0xfe,0xfe,0xfe,0xfe}
#define FOOTER_FILL_RIGHT {0xfe,0xfe,0xfe,0xfe,0x00,0x00,0x00,0x00}
#define FOOTER_ICON_1 {0xfe,0xfe,0x7a,0x02,0x02,0x7e,0xfe,0xfe}

#define TIMER_STATUS 0x00
#define WARN_STATUS 0x01

void show_icons( bool enabled );
void toggle_status( uint8_t sname );

void msgset_timer_icon( bool set );
void msgset_warn_icon( bool set );
