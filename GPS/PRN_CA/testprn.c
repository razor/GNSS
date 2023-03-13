#include <stdio.h>
#include <stdlib.h>

#include "prn_ca.h"

int main(int argc, char **argv) {
	prn_ca_gen gen;
	unsigned char prn;

	if (argc != 2) {
		printf("usage: testprn PRN number\nE.g. testprn 1\n");
		return -1;
	}
	prn = atoi(argv[1]);
	if (prn < 1 || prn > 32) {
		printf("PRN number 1-32\n");
		return -1;
	}
	init_prn_ca_gen(&gen, prn);
	printf("PRN %d: ", prn);

	for (int i = 0; i < 1023; i++) {
		printf("%d", prn_ca_gen_chip(&gen));
		// if ((i+1) % 20 == 0) printf("\n");
	}

	printf("\n");

	free_prn_ca_gen(&gen);
}