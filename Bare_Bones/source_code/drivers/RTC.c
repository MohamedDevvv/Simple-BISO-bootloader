#include <stdint.h>
#include <stdbool.h>

// CMOS RTC Ports
#define CMOS_ADDRESS 0x70
#define CMOS_DATA 0x71

// Function to write a byte to an I/O port
static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

// Function to read a byte from an I/O port
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// Function to read a register from the RTC
uint8_t read_rtc_register(uint8_t reg) {
    outb(CMOS_ADDRESS, reg);
    return inb(CMOS_DATA);
}

// Function to convert BCD to binary
uint8_t bcd_to_bin(uint8_t bcd) {
    return (bcd & 0x0F) + ((bcd >> 4) * 10);
}


// Function to check if the RTC is updating
bool is_update_in_progress() {
    outb(CMOS_ADDRESS, 0x0A);
    return (inb(CMOS_DATA) & 0x80);
}

// Function to get the current time from the RTC
void get_rtc_time(uint8_t* hour, uint8_t* minute) {
    // Wait until the RTC is not updating
    while (is_update_in_progress());

    // Read hour and minute from RTC
    *minute = read_rtc_register(0x02);
    *hour = read_rtc_register(0x04);

    // Convert BCD to binary
    *minute = bcd_to_bin(*minute);
    *hour = bcd_to_bin(*hour);
}

void get_rtc_date(uint8_t* day, uint8_t* month, uint8_t* year) {
    // Wait until the RTC is not updating
    while (is_update_in_progress());

    // Read hour and minute from RTC
    *month = read_rtc_register(0x08);
    *day = read_rtc_register(0x07);
    *year = read_rtc_register(0x09);

    // Convert BCD to binary
    *day = bcd_to_bin(*day);
    *month = bcd_to_bin(*month);
    *year = bcd_to_bin(*year);
}