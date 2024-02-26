# Course Project
# A program that a record shop might use to track its inventory of CDs.

CC := gcc
bin := cddb
src_dir := src
src_files := $(wildcard $(src_dir)/*.c)
obj_dir := obj
obj_files := $(patsubst $(src_dir)/%.c,$(obj_dir)/%.o,$(src_files))
header := $(src_dir)/database.h

.PHONY: all clean

$(bin): $(obj_files)
	@printf "Building \"%s\" program from %s\n" $@ $^
	$(CC) $(CFLAGS) -o $@ $^

$(obj_files): $(obj_dir)/%.o: $(obj_dir)

$(obj_files): $(obj_dir)/%.o: $(src_dir)/%.c $(header)
	@echo "compiling $@ from $<"
	$(CC) -c $(CFLAGS) -o $@  $<

$(obj_dir):
	mkdir -p $@

clean:
	$(RM) $(obj_files)

uninstall: clean
	$(RM) $(prog)
