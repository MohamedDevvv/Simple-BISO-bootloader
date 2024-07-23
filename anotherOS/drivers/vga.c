#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Hardware text mode color constants. */
enum colors {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

static inline uint8_t vga_color(enum colors fg, enum colors bg) 
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str)
{
    size_t len = 0;
    while(str[len])
    {
        len++;
    }
    return len;
}

static const size_t HEIGHT = 25;
static const size_t WIDTH = 80;

size_t ROW;
size_t COLUMN;
uint8_t COLOR;
uint16_t* BUFFER;
// size_t index;

void clear_screen()
{
    ROW = 0;
    COLUMN = 0;
    COLOR = vga_color(WHITE, BLACK);
    BUFFER = (uint16_t*) 0xB8000;
    for(size_t y = 0; y < HEIGHT; y++){
        for(size_t x = 0; x < WIDTH; x++){
            const size_t index = y * WIDTH + x;
            BUFFER[index] = vga_entry(' ', COLOR);
        }
    }
}

void scroll_line()
{
    for (size_t y = 1; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            const size_t source = (y - 1) * WIDTH + x;
            const size_t distance = y * WIDTH + x;
            BUFFER[source] = BUFFER[distance];
        }
    }

    for (size_t x = 0; x < WIDTH; x++) {
        BUFFER[(HEIGHT - 1) * WIDTH + x] = vga_entry(' ', COLOR);
    }

    ROW = HEIGHT - 1;
    COLUMN = 0;
}



void print_char(char c, size_t y, size_t x, uint8_t color)
{
    const size_t index = y * WIDTH +x;
    BUFFER[index] = vga_entry(c, color);
}

void print(char* text, uint8_t color)
{
    size_t length = strlen(text);
    for(size_t i = 0; i < length; i++){
        print_char(text[i], ROW, COLUMN, color);
        if (++COLUMN == WIDTH) {
            COLUMN = 0;
        }
        if (++ROW == HEIGHT) {
                scroll_line();
        }else{
            --ROW;
        }
    }
}

void loading_done(){
    uint8_t color = vga_color(WHITE, BLACK);
    size_t start_point = WIDTH - (COLUMN + 8);
    for(size_t i = 0; i < start_point; i++){
        print(".", color);
    }
    print("[ ", color);
    color = vga_color(GREEN, BLACK);
    print("DONE", color);
    color = vga_color(WHITE, BLACK);
    print(" ]", color);

}

void loading_fail(){
    uint8_t color = vga_color(WHITE, BLACK);
    size_t start_point = WIDTH - (COLUMN + 8);
    for(size_t i = 0; i < start_point; i++){
        print(".", color);
    }
    print("[ ", color);
    color = vga_color(RED, BLACK);
    print("FAIL", color);
    color = vga_color(WHITE, BLACK);
    print(" ]", color);

}

void endl(){
    ROW++;
    COLUMN = 0;
}