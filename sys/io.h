#include <emscripten.h>

unsigned inx(unsigned width, unsigned port) {

	return EM_ASM_INT({

		var io;

		if (window.IO) {
			io = window.IO;
		}
		else if (WindowOrWorkerGlobalScope.IO) {
			io = WindowOrWorkerGlobalScope.IO;
		}
		else {
			console.error("No IO interface");
			return 0;
		}

		return io.in(width, port);

		}, width, port);

}

unsigned inb(unsigned port) {

	return inx(X86EMU_MEMIO_8, port) & 0xff;

}

unsigned inw(unsigned port) {

	return inx(X86EMU_MEMIO_16, port) & 0xffff;

}

unsigned inl(unsigned port) {

	return inx(X86EMU_MEMIO_32, port);

}

unsigned outx(unsigned width, unsigned port, unsigned value) {

	return EM_ASM_INT({

		var io;

		if (window.IO) {
			io = window.IO;
		}
		else if (WindowOrWorkerGlobalScope.IO) {
			io = WindowOrWorkerGlobalScope.IO;
		}
		else {
			console.error("No IO interface");
			return 0;
		}

		return io.out(width, port, value);

		}, width, port, value);

}

void outb(unsigned port, unsigned value) {

	outx(X86EMU_MEMIO_8, port, value & 0xff);

}

void outw(unsigned port, unsigned value) {

	outx(X86EMU_MEMIO_16, port, value & 0xffff);

}

void outl(unsigned port, unsigned value) {

	outx(X86EMU_MEMIO_32, port, value);

}
