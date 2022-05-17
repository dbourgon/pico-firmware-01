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

#include "oledll.h"

uint8_t* get_init_seq(void)
{
   static uint8_t init_seq[25] =  {
        OLED_SLEEP,   // Turn off display
        OLED_MAM_INIT,   // Set memory addressing mode
        OLED_MAM_HORIZ,   // --> Horizontal addressing mode
        OLED_HW_SDSL_LOW,   // Set display start line to 0
        OLED_HW_SRM127,   // Set segment remap: address 127 is mapped to SEG0
        OLED_SET_MUX_INIT,   // Set multiplex ratio
        OLED_SET_MUX_RATIO,   // --> 63
        OLED_COM_REMAP,   //
        OLED_DISP_OFFSET_INIT,
        OLED_DISP_OFFSET,
        OLED_COM_PIN_INIT,
        OLED_COM_PIN_SEQ,
        OLED_DISP_OSC_FREQ_INIT,
        0x80,
        OLED_SET_PRECHARGE_INIT,
        0xf1,
        OLED_SET_VCOM_DESLVL_INIT,
        0x30,
        OLED_SET_CONTRAST,
        0xff,
        OLED_ENTIRE_DISP_RAM,
        OLED_NO_INVERSE,
        0x8d, // ???
        0x14, // ???
        OLED_WAKE };

        return init_seq;
}
