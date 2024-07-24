#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./drivers/vga.h"
#include "./libs/convert.h"
#include "kernel.h"
#include "../drivers/screen.h"
#include "../libs/mem.h"
#include "../libs/string.h"


void kernel_main(){
    isr_install();
    irq_install();
    clear_screen();

    asm("int $2");
    asm("int $3");

    kprint("Type something, it will go through the kernel\n"
        "Type END to halt the CPU or PAGE to request a kmalloc()\n> ");
    
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
    // for(size_t i=0; i<23; i++){
    //     print("scroll down!", vga_color(RED, BLACK));endl();
    // }

}
