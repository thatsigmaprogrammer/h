#include "keys.h"
#include "io.h"
#include <stdint.h>

#define LISTEN_PORT 0x60
#define COMMAND_PORT 0x60

unsigned char scancode;
unsigned char scancodes_buff[256];

void __attribute__((interrupt))
key_isr(void* frame) {
    scancode = inb(LISTEN_PORT);
    scancodes_buff[sizeof(scancodes_buff) + 1];
    return &scancodes_buff;
}


int main() {
    key_isr();
}
