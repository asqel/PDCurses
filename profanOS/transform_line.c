#include "profan_curses.h"

void PDC_transform_line(int lineno, int x, int len, const chtype *srcp) {
	for (int i = 0; i < len; i++) {
		curscr->_y[lineno][x + i] = srcp[i];
	}
}
