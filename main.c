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

#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "main.h"
#include "oled.h"
#include "irq.h"
#include "clock.h"
#include "messages.h"
#include "menu.h"

int main()
{
    bool timerset = false;
    bool warnset = false;

    i2c_config();
    rtc_config();
    gpio_config();

    oled_init();
    oled_clear();

    oled_cmd(OLED_SET_CONTRAST);
    oled_cmd(0x7F);

    while(true){
        oled_clock();
        menu_main();
        show_icons(true);

        if( gpio_get(10) ) {
            menu_time();
            while(gpio_get(10)){oled_clock();}
        }


        sleep_ms(10);
        oled_reset();
    }
}

/*
* Configure i2c
*/
void i2c_config( void )
{
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
}

void gpio_config( void )
{
    gpio_pull_down(10);
    gpio_pull_down(11);
    gpio_pull_down(12);
    gpio_set_input_hysteresis_enabled(10, true);
    gpio_set_input_hysteresis_enabled(11, true);
    gpio_set_input_hysteresis_enabled(12, true);


}
