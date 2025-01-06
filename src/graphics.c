/*

	This file isolates hardware-specific graphics code, in order to allow
	runtime debugging on a non-CX16 platform.

*/
#include "graphics.h"
#ifdef __CX16__
#include <conio.h>
#else
#include <stdio.h>
#endif

void graphics_sayhello() {
#ifdef __CX16__
	cprintf("hello cx16\r\n");
#else
	printf("hello unix\n");
#endif
}

