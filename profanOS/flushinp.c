#include "profan_curses.h"

void PDC_flushinp(void) {
	_profan_I_scancode = 0;
	while (syscall_sc_get())
		;
}