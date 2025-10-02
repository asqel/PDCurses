#include "profan_curses.h"

void PDC_doupdate(void) {
	panda_char_t *buffer = malloc(sizeof(panda_char_t) * COLS * LINES);
	for (int y = 0; y < LINES; y++) {
		for (int x = 0; x < COLS; x++) {
			chtype ch = curscr->_y[y][x];

			char text = ch & A_CHARTEXT;

			int col_pair = PAIR_NUMBER(ch & A_COLOR);
			uint32_t bg_col = 0x0;
			uint32_t fg_col = 0xFFFFFF;
			// TODO ADD COLORS (flemme)
			buffer[x + y * LINES].bg_color = bg_col;
			buffer[x + y * LINES].fg_color = fg_col;
			buffer[x + y * LINES].decoration = 0;
			buffer[x + y * LINES].character = text;
		}
	}
	panda_print_raw(buffer, LINES * COLS);
	panda_draw_cursor(curscr->_curx, curscr->_cury);
	free(buffer);
}
