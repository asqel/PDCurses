#include "profan_curses.h"

void PDC_gotoyx(int y, int x) {
	curscr->_cury = y;
	curscr->_curx = x;
	panda_draw_cursor(x, y);
}
