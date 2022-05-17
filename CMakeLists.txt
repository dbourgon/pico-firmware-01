cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(oled C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(oled main.c oled.c irq.c clock.c messages.c menu.c ssd1306_font01.c oledll.c)

target_link_libraries(oled pico_stdlib hardware_i2c hardware_rtc hardware_irq hardware_adc)

pico_add_extra_outputs(oled)
