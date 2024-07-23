#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./drivers/vga.h"


void kernel_main(){
    clear_screen();

    uint8_t color = vga_color(WHITE, BLACK);

    print("Booting Kernel", color);
    loading_done();

    print("Load VGA Text Mode Drivers (TTY)", color);
    loading_done();

    print("Get RTC from Bios", color);
    loading_fail();

    color = vga_color(LIGHT_BLUE, BLACK);
    print("Welcome to Another X86 os"); endl();
    print("Hello, World!");
}