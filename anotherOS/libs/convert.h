#ifndef CONVERT_H
#define CONVERT_H
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

void init_timer(uint32_t frequency);
void timer_wait(int ticks);

#endif // CONVERT_H