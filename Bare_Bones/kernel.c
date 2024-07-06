#include "VGA_TTY.h"
#include "RTC.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
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

	char* string = "Hello, World!!";
	uint8_t color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_WHITE);

	terminal_center_writing(string, color);
	terminal_newline();

	terminal_writestring("Hi, I love VGA drivers file", color);
	terminal_newline();

	color = vga_entry_color(VGA_COLOR_BLUE, VGA_COLOR_WHITE);
	terminal_center_writing("Yay! I am here to say the files are updated!", color);
}