#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>

static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ __volatile__("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

static inline void outb(uint16_t port, uint8_t data) {
    __asm__ __volatile__("outb %0, %1" : : "a"(data), "Nd"(port));
}

static void itoa(int value, char* str, int base)
{
        char *ptr = str, *ptr1 = str, tmp_char;
    int tmp_value;

    if (value == 0) {
        *str++ = '0';
        *str = '\0';
        return;
    }

    while (value) {
        tmp_value = value % base;
        if (tmp_value < 10) {
            tmp_value += '0';
        } else {
            tmp_value += 'a' - 10;
        }
        *ptr++ = tmp_value;
        value /= base;
    }

    // Null terminate string
    *ptr-- = '\0';

    // Reverse string
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
}

#endif
