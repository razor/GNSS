#include <stdlib.h>
#include "prn_ca.h"

int init_prn_ca_gen(prn_ca_gen *gen, unsigned char prn) {
	if (prn < 1 || prn > 32) return -1;
	gen->g1 = (shiftreg *)malloc(sizeof(shiftreg));
	gen->g2 = (shiftreg *)malloc(sizeof(shiftreg));
	gen->g1->bits = 10;
	gen->g2->bits = 10;
	gen->bits = 10;
	gen->curchip = 0;
	gen->g1->lock = 1;
	gen->prn = prn;
	setepoch(gen->g1, gen->bits);
	setepoch(gen->g2, gen->bits);

}

unsigned char prn_ca_gen_chip(prn_ca_gen *gen) {
	unsigned char val;
	tapsel sel = PRN_TAPSEL[gen->prn - 1].sel;
	val = 0;
	val = tapfbshift(gen->g1, 2, G1TAPS);
	val ^= tapfbshift_sel(gen->g2, 6, G2TAPS, sel);

	return val;
}

void free_prn_ca_gen(prn_ca_gen *gen) {
	if (gen->g1) free(gen->g1);
	if (gen->g2) free(gen->g2);

	gen->g1 = NULL;
	gen->g2 = NULL;
	return ;
}

