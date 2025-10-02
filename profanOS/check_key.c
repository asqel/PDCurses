#include "profan_curses.h"

uint32_t _profan_I_scancode = 0;

bool PDC_check_key(void) {
	if (_profan_I_scancode > 0)
		return TRUE;
	_profan_I_scancode = syscall_sc_get();
	return _profan_I_scancode > 0;
}
