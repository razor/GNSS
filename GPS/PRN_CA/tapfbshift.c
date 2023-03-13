#include "tapfbshift.h"

void setepoch(shiftreg *sftreg, unsigned char numbits) {
	unsigned int val = (1 << numbits) - 1;
	sftreg->reg = val;
}

static unsigned char shift(shiftreg *sftreg) {
	unsigned char val = sftreg->reg & 0x1;
	sftreg->reg >>= 1;
	return val;
}

static unsigned char getbit(shiftreg *sftreg, unsigned int bit) {
	unsigned int mask = 1 << (sftreg->bits - bit);
	return (sftreg->reg & mask) > 0;
}

unsigned char tapfbshift(shiftreg *sftreg, unsigned char tapcount, unsigned char *taps) {
	unsigned char val, tap;
	unsigned int vfb = 0;

	while (tapcount--) {
		tap = *(taps + tapcount);
		if (tap > sftreg->bits) return -1;
		vfb ^= getbit(sftreg, tap);
	}

	val = shift(sftreg);

	if (vfb) {
		vfb = vfb << (sftreg->bits - 1);
		sftreg->reg |= vfb;
	}
	return val;
}

unsigned char tapfbshift_sel(shiftreg *sftreg, unsigned char tapcount, unsigned char *taps, tapsel sel) {
	unsigned char val = 0;
	
	while (sel.tapsel_num --) {
		val ^= getbit(sftreg, sel.taps_sel[sel.tapsel_num]);
	}

	tapfbshift(sftreg, tapcount, taps);
	return val;
}