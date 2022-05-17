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
#include <stdlib.h>
#include <stdint.h>

uint8_t* get_init_seq(void);

/*
 * i2c commands for OLED display
 */

/*
 * Fundamental Commands
 *
 */
#define OLED_SET_CONTRAST               0x81
#define OLED_DEFAULT_CONTRAST           0x7F

#define OLED_ENTIRE_DISP_RAM            0xA4
#define OLED_ENTIRE_DISP_ON             0xA5

#define OLED_NO_INVERSE                 0xA6
#define OLED_INVERSE                    0xA7

#define OLED_SLEEP                      0xAE
#define OLED_WAKE                       0xAF


/*
 * Horizontal Scroll commands
 *
 */
#define OLED_HSCROLL_INIT_RIGHT         0x26
#define OLED_HSCROLL_INIT_LEFT          0x27
#define OLED_HSCROLL_A_DUMMY            0x00

#define OLED_HSCROLL_B_SPA0             0x00    // Start page address 0
#define OLED_HSCROLL_B_SPA1             0x01
#define OLED_HSCROLL_B_SPA2             0x02
#define OLED_HSCROLL_B_SPA3             0x03
#define OLED_HSCROLL_B_SPA4             0x04
#define OLED_HSCROLL_B_SPA5             0x05
#define OLED_HSCROLL_B_SPA6             0x06
#define OLED_HSCROLL_B_SPA7             0x07

#define OLED_HSCROLL_C_TI2F             0x07    // Time interval 2 frames
#define OLED_HSCROLL_C_TI3F             0x04
#define OLED_HSCROLL_C_TI4F             0x05
#define OLED_HSCROLL_C_TI5F             0x00
#define OLED_HSCROLL_C_TI25F            0x06
#define OLED_HSCROLL_C_TI64F            0x01
#define OLED_HSCROLL_C_TI128F           0x02
#define OLED_HSCROLL_C_TI256F           0x03

#define OLED_HSCROLL_D_EPA0             0x00   // End page address 0
#define OLED_HSCROLL_D_EPA1             0x01
#define OLED_HSCROLL_D_EPA2             0x02
#define OLED_HSCROLL_D_EPA3             0x03
#define OLED_HSCROLL_D_EPA4             0x04
#define OLED_HSCROLL_D_EPA5             0x05
#define OLED_HSCROLL_D_EPA6             0x06
#define OLED_HSCROLL_D_EPA7             0x07

#define OLED_HSCROLL_E_DUMMY            0x00
#define OLED_HSCROLL_F_DUMMY            0xFF

/*
 * Vertical and Horizontal scrolling
 *
 */

#define OLED_VHSCROLL_INIT_RIGHT        0x29
#define OLED_VHSCROLL_INIT_LEFT         0x2A

#define OLED_VHSCROLL_A_DUMMY           0x00

#define OLED_VHSCROLL_B_SPA0            0x00
#define OLED_VHSCROLL_B_SPA1            0x01
#define OLED_VHSCROLL_B_SPA2            0x02
#define OLED_VHSCROLL_B_SPA3            0x03
#define OLED_VHSCROLL_B_SPA4            0x04
#define OLED_VHSCROLL_B_SPA5            0x05
#define OLED_VHSCROLL_B_SPA6            0x06
#define OLED_VHSCROLL_B_SPA7            0x07

#define OLED_VHSCROLL_C_TI2F            0x07
#define OLED_VHSCROLL_C_TI3F            0x04
#define OLED_VHSCROLL_C_TI4F            0x05
#define OLED_VHSCROLL_C_TI5F            0x00
#define OLED_VHSCROLL_C_TI25F           0x06
#define OLED_VHSCROLL_C_TI64F           0x01
#define OLED_VHSCROLL_C_TI128F          0x02
#define OLED_VHSCROLL_C_TI256F          0x03

#define OLED_VHSCROLL_D_EPA0            0x00
#define OLED_VHSCROLL_D_EPA1            0x01
#define OLED_VHSCROLL_D_EPA2            0x02
#define OLED_VHSCROLL_D_EPA3            0x03
#define OLED_VHSCROLL_D_EPA4            0x04
#define OLED_VHSCROLL_D_EPA5            0x05
#define OLED_VHSCROLL_D_EPA6            0x06
#define OLED_VHSCROLL_D_EPA7            0x07

#define OLED_VHSCROLL_E_VSO             0x00

/*
 * Deactivate Scrolling
 */

#define OLED_SCROLL_STOP                0x2E
#define OLED_SCROLL_START               0x2F

/*
 * Set vertical scroll area
 */

#define OLED_VSCROLLAREA_INIT           0xA3

#define OLED_VSCROLLAREA_A_TFAR         0x00
#define OLED_VSCROLLAREA_B_SAR          0x40

/*
 * Addressing setting commands
 */


/* Set memory addressing mode */
#define OLED_MAM_INIT                   0x20
#define OLED_MAM_HORIZ                  0x00
#define OLED_MAM_VERT                   0x01
#define OLED_MAM_PAM                    0x02

/* Set column start address for page addressing mode */
#define OLED_PAM_LCSA                   0x00
#define OLED_PAM_HCSA                   0x00

/* Set page start address for page addressing mode */
#define OLED_PAM_PSA0                   0xB0
#define OLED_PAM_PSA1                   0xB1
#define OLED_PAM_PSA2                   0xB2
#define OLED_PAM_PSA3                   0xB3
#define OLED_PAM_PSA4                   0xB4
#define OLED_PAM_PSA5                   0xB5
#define OLED_PAM_PSA6                   0xB6
#define OLED_PAM_PSA7                   0xB7

/* Column start and end address for HV addressing mode */
#define OLED_HVAM_SCA_INIT              0x21
#define OLED_HVAM_SCA_CSA               0x00
#define OLED_HVAM_SCA_CEA               0x7F

/* Set page address for HV addressing mode */
#define OLED_HVAM_SPA_INIT              0x22
#define OLED_HVAM_SPA_PSA               0x00
#define OLED_HVAM_SPA_PEA               0x07


/*
 *
 * Hardware Configuration
 */

/*Set display start line */
#define OLED_HW_SDSL_LOW                    0x40
#define OLED_HW_SDSL_HIGH                   0x7F

/* Set Segment Re-Map */
#define OLED_HW_SRM0                        0xA0
#define OLED_HW_SRM127                      0xA1

/* Set multiplex ratio */
#define OLED_SET_MUX_INIT                   0xA8
#define OLED_SET_MUX_RATIO                  0x3F

/* Set COM output scan direction */

#define OLED_COM_NORM                       0xC0
#define OLED_COM_REMAP                      0xC8

/* Set display offset */

#define OLED_DISP_OFFSET_INIT               0xD3
#define OLED_DISP_OFFSET                    0x00

/* Set com pins hardware configuration */

#define OLED_COM_PIN_INIT                   0xDA
#define OLED_COM_PIN_SEQ                    0x12
/*
* TODO:
* add other com pin configurations */


/* Display clock div ratio / osc freq */
#define OLED_DISP_OSC_FREQ_INIT             0xD5

#define OLED_SET_PRECHARGE_INIT             0xD9

#define OLED_SET_VCOM_DESLVL_INIT           0xDB

#define OLED_NOP                            0xE3
