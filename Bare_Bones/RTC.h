#include <stdint.h>
#include <stdbool.h>

#define CMOS_ADDRESS 0x70
#define CMOS_DATA 0x71

uint8_t read_rtc_register(uint8_t reg) {
    outb(CMOS_ADDRESS, reg);
    return inb(CMOS_DATA);
}

uint8_t bcd_to_bin(uint8_t bcd) {
    return (bcd & 0x0F) + ((bcd / 16) * 10);
}

bool is_update_in_progress() {
    outb(CMOS_ADDRESS, 0x0A);
    return (inb(CMOS_DATA) & 0x80);
}