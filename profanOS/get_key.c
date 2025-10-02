#include "profan_curses.h"


#define MOD_SHIFT_L (1 << 0)
#define MOD_SHIFT_R (1 << 1)
#define MOD_CTRL_L  (1 << 2)
#define MOD_CTRL_R  (1 << 3)
#define MOD_ALT_L   (1 << 4)
#define MOD_ALT_R   (1 << 5)


static int modifiers = 0;

static void set_modifier(int mask, int is_set) {
    if (is_set)
        modifiers |= mask;
    else
        modifiers &= ~mask;
}

static int is_alt() {
	return (modifiers & MOD_ALT_L) | (modifiers & MOD_ALT_R);
}

static int is_ctrl() {
	return (modifiers & MOD_CTRL_L) | (modifiers & MOD_CTRL_R);
}

static int is_shift() {
	return (modifiers & MOD_SHIFT_L) | (modifiers & MOD_SHIFT_R);
}

static int keybuff[16] = {0};
static int keybuff_len = 0;

static void push(char c) {
	keybuff[keybuff_len++] = c;
}

static char pop() {
	int ret = keybuff[0];
	for (int i = 0; i < keybuff_len - 1; i++)
		keybuff[i] = keybuff[i + 1];
	keybuff_len--;
	return ret;
}

static int handle_extend(uint32_t scancode) {
	// TODO implement arrows
	return -1;
}

int handle_key(uint32_t scancode) {
	// TODO later handle right control (its an extend)
	// TODO same for alt right
	if (scancode == PS_LEFT_SHIFT) {
		set_modifier(MOD_SHIFT_L, 1);
		return -1;
	}
	if (scancode == PS_RIGHT_SHIFT) {
		set_modifier(MOD_SHIFT_R, 1);
		return -1;
	}
	if (scancode == PS_LEFT_CTRL) {
		set_modifier(MOD_CTRL_L, 1);
		return -1;
	}
	if (scancode == PS_LEFT_ALT) {
		set_modifier(MOD_ALT_L, 1);
		return -1;
	}

	if (scancode == PS_RELEASED(PS_LEFT_SHIFT)) {
		set_modifier(MOD_SHIFT_L, 0);
		return handle_key(syscall_sc_get());
	}
	if (scancode == PS_RELEASED(PS_RIGHT_SHIFT)) {
		set_modifier(MOD_SHIFT_R, 0);
		return handle_key(syscall_sc_get());
	}
	if (scancode == PS_RELEASED(PS_LEFT_CTRL)) {
		set_modifier(MOD_CTRL_L, 0);
		return handle_key(syscall_sc_get());
	}

	if (scancode == PS_RELEASED(PS_LEFT_ALT)) {
		set_modifier(MOD_ALT_L, 0);
		return handle_key(syscall_sc_get());
	}
	if (scancode == PS_EXTEND)
		return handle_extend(syscall_sc_get());

	if (scancode == PS_ESC)
		return '\e';
	char text = profan_kb_get_char(scancode, is_shift());
	if (text == 0)
		return -1;
	if ('0' <= text && text <= '9') {
		if (!is_alt())
			return text;
		push('\e');
		push(text);
		return pop();
	}
	if (isalpha(text)) {
		if (is_ctrl()) {
			text = toupper(text);
			text = text - 'A' + 1;
		}
		if (!is_alt())
			return text;
		push('\e');
		push(text);
		return pop();
	}
	if (is_alt())
		push('\e');
	push(text);
	return pop();
}

int PDC_get_key(void) {
	if (keybuff_len)
		return pop();
	if (_profan_I_scancode) {
		int ret = handle_key(_profan_I_scancode);
		_profan_I_scancode = 0;
		return ret;
	}
	return handle_key(syscall_sc_get());
}

int PDC_modifiers_set(void) {
    int state = 0;

    if (modifiers & MOD_SHIFT_L)
		state |= PDC_KEY_MODIFIER_SHIFT;
    if (modifiers & MOD_SHIFT_R)
		state |= PDC_KEY_MODIFIER_SHIFT;
    if (modifiers & MOD_CTRL_L)
		state |= PDC_KEY_MODIFIER_CONTROL;
    if (modifiers & MOD_CTRL_R)
		state |= PDC_KEY_MODIFIER_CONTROL;
    if (modifiers & MOD_ALT_L)
		state |= PDC_KEY_MODIFIER_ALT;
    if (modifiers & MOD_ALT_R)
		state |= PDC_KEY_MODIFIER_ALT;

    return state;
}

int PDC_mouse_set(void) {
	return 0;
}

void PDC_set_keyboard_binary(bool on) {

}