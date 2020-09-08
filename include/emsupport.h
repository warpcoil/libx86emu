#ifndef __EMSUPPORT_H__
#define __EMSUPPORT_H__

#include <stdio.h>

void outb(unsigned short port, unsigned char byte) {
    printf("%s%hu%s%hhx", "outb:: port:", port, ", value:", byte);
}

void outw(unsigned short port, unsigned short word) {
    printf("%s%hu%s%hx", "outw:: port:", port, ", value:", word);
}

void outl(unsigned short port, unsigned long dword) {
    printf("%s%hu%s%lx", "outl:: port:", port, ", value:", dword);
}

unsigned char inb(unsigned short port) {
    printf("%s%hu", "inb:: port:", port);
    return 0;
}

unsigned short inw(unsigned short port) {
    printf("%s%hu", "inw:: port:", port);
    return 0;
}

unsigned long inl(unsigned short port) {
    printf("%s%hu", "inl:: port:", port);
    return 0;
}

#endif

