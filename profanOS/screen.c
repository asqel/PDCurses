#include "profan_curses.h"

int PDC_resize_screen(int nlines, int ncols) {
	return ERR;
}

void PDC_restore_screen_mode(int i) {

}

void PDC_save_screen_mode(int i) {

}

static void *screen_profan = NULL;

void PDC_scr_close(void) {
	panda_screen_restore(screen_profan);
}

void PDC_scr_free(void) {
	panda_screen_free(screen_profan);
}

int PDC_scr_open(void) {
	screen_profan = panda_screen_backup();
}