#include "profan_curses.h"

int PDC_clearclipboard(void) {
	return 1;
}
int PDC_freeclipboard(char *contents) {
	return 1;
}
int PDC_getclipboard(char **contents, long *length) {
	return 1;
}
int PDC_setclipboard(const char *contents, long length) {
	return 1;
}
int PDC_set_blink(bool blinkon) {
	return 1;
}
int PDC_set_bold(bool boldon) {
	return 1;
}
void PDC_set_title(const char *title) {
	return 1;
}