#include "profan_curses.h"

int PDC_get_rows(void) {
	int cols;
	int lines;
	panda_get_size(&cols, &lines);
	return lines;
}