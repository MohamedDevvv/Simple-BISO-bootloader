// Kernel File

#include "drivers/vga.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i686__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	char* string = "Hello, World!!";
	uint8_t color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
	terminal_center_writing(string, color);
    terminal_newline();

	color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	for(size_t i = 0; i < 80; i++){
		terminal_writestring("-", color);
	}
    terminal_newline();
	
	color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
	terminal_writestring("Hi, I love VGA drivers file", color);
	terminal_newline();

	color = vga_entry_color(VGA_COLOR_BLUE, VGA_COLOR_BLACK);
	terminal_center_writing("Yay! I am here to say the files are updated!", color);
	
	color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	terminal_newline();
	terminal_writestring("I am an i686 kernel (32bit kernel)", color);
    terminal_newline();
	terminal_writestring("I made by a tutorial from osdev.org, gifted chatgpt from a friend and love from idiot man called:", color);
	terminal_newline();
	terminal_writestring("Mohammed Saleh!", color);
}