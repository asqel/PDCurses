#ifndef PROFAN_CURSES_H
#define PROFAN_CURSES_H

#include "curses.h"
#include <stdint.h>
#include <modules/panda.h>
#include <profan/syscall.h>
#include <profan.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

extern WINDOW *curscr;
extern uint32_t _profan_I_scancode;

// ps/2 keys

#define PS_ESC 1
#define PS_1 2
#define PS_2 3
#define PS_3 4
#define PS_4 5
#define PS_5 6
#define PS_6 7
#define PS_7 8
#define PS_8 9
#define PS_9 0xa
#define PS_0 0xb
#define PS_MINUS 0xC
#define PS_EQUAL 0xD
#define PS_BACKSPACE 0xE
#define PS_TAB 0xF
#define PS_Q 0x10
#define PS_W 0x11
#define PS_E 0x12
#define PS_R 0x13
#define PS_T 0x14
#define PS_Y 0x15
#define PS_U 0x16
#define PS_I 0x17
#define PS_O 0x18
#define PS_P 0x19
#define PS_LEFT_BRACK 0x1A
#define PS_RIGHT_BRACK 0x1B
#define PS_ENTER 0x1C
#define PS_LEFT_CTRL 0x1D
#define PS_A 0x1E
#define PS_S 0x1F
#define PS_D 0x20
#define PS_F 0x21
#define PS_G 0x22
#define PS_H 0x23
#define PS_J 0x24
#define PS_K 0x25
#define PS_L 0x26
#define PS_SEMICOL 0x27
#define PS_SQUOTE 0x28
#define PS_BQUOTE 0x29
#define PS_LEFT_SHIFT 0x2A
#define PS_BACK_SLASH 0x2B
#define PS_Z 0x2C
#define PS_X 0x2D
#define PS_C 0x2E
#define PS_V 0x2F
#define PS_B 0x30
#define PS_N 0x31
#define PS_M 0x32
#define PS_COMMA 0x33
#define PS_DOT 0x34
#define PS_SLASH 0x35
#define PS_RIGHT_SHIFT 0x36
#define PS_KP_STAR 0x37
#define PS_LEFT_ALT 0x38
#define PS_SPACE 0x39
#define PS_CAPSLOCK 0x3A
#define PS_F1 0x3B
#define PS_F2 0x3C
#define PS_F3 0x3D
#define PS_F4 0x3E
#define PS_F5 0x3F
#define PS_F6 0x40
#define PS_F7 0x41
#define PS_F8 0x42
#define PS_F9 0x43
#define PS_F10 0x44
#define PS_NUMLOCK 0x45
#define PS_SCROLLLOCK 0x46
#define PS_KP_7 0x47
#define PS_KP_8 0x48
#define PS_KP_9 0x49
#define PS_KP_MINUS 0x4A
#define PS_KP_4 0x4B
#define PS_KP_5 0x4C
#define PS_KP_6 0x4D
#define PS_KP_PLUS 0x4E
#define PS_KP_2 0x50
#define PS_KP_3 0x51
#define PS_KP_0 0x52
#define PS_KP_DOT 0x53
#define PS_F11 0x57
#define PS_F12 0x58

#define PS_RELEASED(X) (X + 0x80)

#define PS_EXTEND 0xE0

#endif
