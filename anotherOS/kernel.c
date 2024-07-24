#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./drivers/vga.h"
#include "libs/convert.h"

 //Play sound using built-in speaker
 static void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint8_t) (Div) );
 	outb(0x42, (uint8_t) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }
 
 //make it shut up
 static void nosound() {
 	uint8_t tmp = inb(0x61) & 0xFC;
     
 	outb(0x61, tmp);
 }
 
 //Make a beep
 void beep() {
 	 play_sound(1000);
 	 timer_wait(10);
 	 nosound();
          //set_PIT_2(old_frequency);
 }

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
    // for(size_t i=0; i<23; i++){
    //     print("scroll down!", vga_color(RED, BLACK));endl();
    // }
    beep();

}