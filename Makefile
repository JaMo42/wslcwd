
ifndef DIR
	DIR := ~/.local/bin/
endif

ifdef DRIVES
	drive_flag := -DDRIVE_LETTERS=\"$(DRIVES)\"
else
	drive_flag :=
endif

all:
	gcc -march=native -O3 $(drive_flag) -o wslcwd wslcwd.c

install:
	@cp -v wslcwd $(DIR)

