/*


*/
#include <6502.h>
#include <stdlib.h>
#include <cx16.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "graphics.h"
#include "characters.h"
#include "splash.h"

void setPETFont()
{
   // set PET font
   struct regs fontregs;
   fontregs.a = 4; // PET-like
   fontregs.pc = 0xff62;
   _sys(&fontregs);
}

void init() {
	// initialization code goes here
	setPETFont();
	_randomize();
}

void main() {
	init();
	login("character registry", "2024-06-01");
	printf("\n\n\n                         press a key to continue\n");
	cgetc();
	clrscr();
	_randomize();
	characters_loadRegistry();
	characters_showRegistry();
}
