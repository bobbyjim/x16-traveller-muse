/*


*/
#include <6502.h>
#include <stdlib.h>

#include "graphics.h"

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
	graphics_sayhello();
	//for(;;) {
		// main loop code should go here
	//}
}
