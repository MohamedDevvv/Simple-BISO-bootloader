#ifndef RTC_H
#define RTC_H

#include <stdint.h>
#include <stdbool.h>

#define CMOS_ADDRESS 0x70
#define CMOS_DATA 0x71

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

uint8_t read_rtc_register(uint8_t reg);
uint8_t bcd_to_bin(uint8_t bcd);
bool is_update_in_progress();
void get_rtc_time(uint8_t* hour, uint8_t* minute);
void get_rtc_date(uint8_t* day, uint8_t* month, uint8_t* year);

#endif // RTC_H
