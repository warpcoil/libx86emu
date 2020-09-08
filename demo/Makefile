CC         = emcc
CFLAGS     = -s MAIN_MODULE=1 -g -Wall -fomit-frame-pointer -O2

.PHONY: clean

x86emu-demo.html: x86emu-demo.c
	$(CC) $(CFLAGS) $< -lx86emu -o $@

clean:
	rm -f *~ *.o x86emu-demo.html
