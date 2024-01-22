# Course Project
# A program that a record shop might use to track its inventory of CDs.

prog := cddb
src_files := main.c
obj_files := $(patsubst %.c,%.o,$(src_files))

.PHONY: all clean

all: $(obj_files)
	@echo "building $(prog) from $^"
	$(CC) $(CFLAGS) -o $(prog) $^

%.o: %.c
	@echo "compiling $@ from $^"
	$(CC) $(CFLAGS) -c -o $@  $^

clean:
	rm -f $(obj_files)

uninstall: clean
	rm -f $(prog)
