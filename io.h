#ifndef IO_LIB_H
#define IO_LIB_H
#include <stdint.h>

extern "C" 
{
    static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile ("inb %1, %0"
                          : "=a"(result)
                          : "Nd"(port));
    return result;
}

static inline void outb(uint16_t port, uint8_t value) {
    __asm__ volatile ("outb %0, %1"
                          :
                          : "a"(value), "Nd"(port));
}
}

#endif