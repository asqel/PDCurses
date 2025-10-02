
profan_path = ../profanos
CFLAGS = -fPIC -ffreestanding -fno-exceptions -m32 -I$(profan_path)/include/zlibs -I$(profan_path)/include/addons -nostdinc -U_WIN32 -U__linux__ -Iinclude -Isrc -D__profanOS__=1 -I..
LDFLAGS = -m elf_i386 -nostdlib -shared -L $(profan_path)/out/zlibs -lc

CC = gcc
LD = ld

SRC = $(wildcard profanOS/*.c) $(wildcard pdcurses/*.c)
OBJ = $(SRC:.c=.o)

NAME = libpdcurses.so

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

install: $(NAME)
	mkdir -p $(profan_path)/include/addons/
	mkdir -p $(profan_path)/out/zlibs/
	cp $(NAME) $(profan_path)/out/zlibs/$(NAME)
	cp curses.h $(profan_path)/include/addons/

.PHONY: re fclean clean all install
