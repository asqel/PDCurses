#include "profan_curses.h"

void PDC_beep(void) {

}

void PDC_napms(int ms) {
	usleep(ms * 1000);
}

const char *PDC_sysname(void) {
	return "profanOS";
}