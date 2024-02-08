# Course Project
# A program that a record shop might use to track its inventory of CDs.

CC := gcc
prog := cddb
src_files := main.c input.c output.c util.c
obj_files := $(patsubst %.c,%.o,$(src_files))
header := database.h

.PHONY: all clean

$(prog): $(obj_files)
	@echo "building \"$(prog)\" program from $^"
	$(CC) $(CFLAGS) -o $(prog) $^

$(obj_files): %.o: %.c $(header)
	@echo "compiling $@ from $^"
	$(CC) $(CFLAGS) -c -o $@  $^

clean:
	rm -f $(obj_files)

uninstall: clean
	rm -f $(prog)
