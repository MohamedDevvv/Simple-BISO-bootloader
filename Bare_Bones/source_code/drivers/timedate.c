#include "VGA_TTY.h"
#include "RTC.h"
#include "convert.h"

void strcat(char* dest, const char* src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void print_time(){
    uint8_t hour, minute;
    get_rtc_time(&hour, &minute);

    char hour_str[3];  // String buffer for hour
    char minute_str[3]; // String buffer for minute

    // Convert hour and minute to strings
    itoa(hour, hour_str, 10);
    itoa(minute, minute_str, 10);

    uint8_t color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_WHITE);

    // Write hour and minute to the terminal
    terminal_writestring(hour_str, color);
    terminal_writestring(" : ", color);
    terminal_writestring(minute_str, color);
}

void print_date(){
    uint8_t day, month, year;
    get_rtc_date(&day, &month, &year);

    char day_str[3];
    char month_str[3];
    char year_str[3];

    // Convert hour and minute to strings
    itoa(day, day_str, 10);
    itoa(month, month_str, 10);
    itoa(year, year_str, 10);

    uint8_t color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_WHITE);

    char date_str[11]; // DD/MM/YYYY format
    date_str[0] = '\0'; // Initialize the string
    
    strcat(date_str, day_str);
    strcat(date_str, "/");
    strcat(date_str, month_str);
    strcat(date_str, "/");
    strcat(date_str, year_str);

    // Write hour and minute to the terminal
    terminal_endl(date_str, color);
}