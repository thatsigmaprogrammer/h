#include "keys.h"
#include "io.h"
#include <stdint.h>

#define LISTEN_PORT 0x60

unsigned char scancode;
unsigned char scancodes_buff[256];

void __attribute__((interrupt))
key_isr(struct interrupt_frame* frame) 
{
    scancode = inb(LISTEN_PORT);
    static int indx = 0;
    if(indx < sizeof(scancodes_buff))
    {
        scancodes_buff[indx++] = scancode
    } else
    {
        indx = 0;
    }

    outb(0x20, 0x20);
}

