// Kernel File

#include "VGA_TTY.h"
#include "RTC.h"
#include "convert.h"
#include "timedate.h"
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i686__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

// colors
// 	VGA_COLOR_BLACK
// 	VGA_COLOR_BLUE
// 	VGA_COLOR_GREEN
// 	VGA_COLOR_CYAN
// 	VGA_COLOR_RED
// 	VGA_COLOR_MAGENTA
// 	VGA_COLOR_BROWN
// 	VGA_COLOR_LIGHT_GREY
// 	VGA_COLOR_DARK_GREY
// 	VGA_COLOR_LIGHT_BLUE 
// 	VGA_COLOR_LIGHT_GREEN
// 	VGA_COLOR_LIGHT_CYAN
// 	VGA_COLOR_LIGHT_RED
// 	VGA_COLOR_LIGHT_MAGENTA
// 	VGA_COLOR_LIGHT_BROWN
// 	VGA_COLOR_WHITE

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	print_time();

	char* string = "Hello, World!!";
	uint8_t color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_WHITE);
	terminal_center_writing(string, color);

	print_date();

	color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	for(size_t i = 0; i < 80; i++){
		terminal_writestring("-", color);
	}
	
	color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_WHITE);
	terminal_writestring("Hi, I love VGA drivers file", color);
	terminal_newline();

	color = vga_entry_color(VGA_COLOR_BLUE, VGA_COLOR_WHITE);
	terminal_center_writing("Yay! I am here to say the files are updated!", color);
	
	color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	terminal_newline();
	terminal_writestring("I am an i686 kernel (32bit kernel)", color);
        terminal_newline(); // Corrected function call
	terminal_writestring("I made by a tutorial from osdev.org, gifted chatgpt from a friend and love from idiot man called:", color);
	terminal_newline();
	terminal_writestring("Mohammed Saleh!", color);
}
