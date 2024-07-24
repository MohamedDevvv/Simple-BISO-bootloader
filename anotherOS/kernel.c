#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./drivers/vga.h"
#include "libs/convert.h"

void kernel_main(){
    clear_screen();

    uint8_t color = vga_color(WHITE, BLACK);

    print("Booting Kernel", color); 
    loading_done();
    print("Load VGA Text Mode Drivers (TTY)", color);
    loading_done();
    print("Get RTC from Bios", color);
    loading_fail();

    print("Welcome to Another x86 OS!", vga_color(LIGHT_BLUE, BLACK));endl();

    print("Info:-", color);endl();
    print("Kernel Version: r56416-alpha (32bit)", color);endl();
    print("VGA in text mode", color);endl();
    print("Made by Mohammed Saleh", color);endl();

}