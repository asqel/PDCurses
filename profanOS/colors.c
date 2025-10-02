#include "profan_curses.h"

struct RGB { short r, g, b; };
struct RGB palette[16] = {
    {0,0,0},       // COLOR_BLACK
    {1000,0,0},    // COLOR_RED
    {0,1000,0},    // COLOR_GREEN
    {1000,1000,0}, // COLOR_YELLOW
    {0,0,1000},    // COLOR_BLUE
    {1000,0,1000}, // COLOR_MAGENTA
    {0,1000,1000}, // COLOR_CYAN
    {1000,1000,1000}, // COLOR_WHITE
    // éventuellement les “bright” colors si tu veux 8 de plus
};

void PDC_init_color(short color, short r, short g, short b) {
    if (color < 0 || color >= 16) return;
    palette[color].r = r;
    palette[color].g = g;
    palette[color].b = b;
}

int PDC_color_content(short color, short *r, short *g, short *b) {
    if (color < 0 || color >= 16) return ERR;
    *r = palette[color].r;
    *g = palette[color].g;
    *b = palette[color].b;
    return OK;
}