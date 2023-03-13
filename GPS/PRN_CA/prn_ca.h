#include "tapfbshift.h"

static unsigned char G1TAPS[2] = {3, 10};
static unsigned char G2TAPS[6] = {2, 3, 6, 8, 9, 10};

typedef struct prn_ca_tapsel {
	unsigned char prn;
	tapsel sel;
} prn_ca_tapsel;



typedef struct prn_ca_gen {
	shiftreg *g1, *g2;
	unsigned char prn;
	unsigned char bits;
	unsigned int curchip;
} prn_ca_gen;

static prn_ca_tapsel PRN_TAPSEL[32] = {{1, {2, 2, 6}}, \
	{2, {2, 3, 7}}, \
	{3, {2, 4, 8}}, \
	{4, {2, 5, 9}}, \
	{5, {2, 1, 9}}, \
	{6, {2, 2, 6}}, \
	{7, {2, 1, 8}}, \
	{8, {2, 2, 9}}, \
	{9, {2, 3, 10}}, \
	{10, {2, 2, 3}}, \
	{11, {2, 3, 4}}, \
	{12, {2, 5, 6}}, \
	{13, {2, 6, 7}}, \
	{14, {2, 7, 8}}, \
	{15, {2, 8, 9}}, \
	{16, {2, 9, 10}}, \
	{17, {2, 1, 4}}, \
	{18, {2, 2, 5}}, \
	{19, {2, 3, 6}}, \
	{20, {2, 4, 7}}, \
	{21, {2, 5, 8}}, \
	{22, {2, 6, 9}}, \
	{23, {2, 1, 3}}, \
	{24, {2, 4, 6}}, \
	{25, {2, 5, 7}}, \
	{26, {2, 6, 8}}, \
	{27, {2, 7, 9}}, \
	{28, {2, 8, 10}}, \
	{29, {2, 1, 6}}, \
	{30, {2, 2, 7}}, \
	{31, {2, 3, 8}}, \
	{32, {2, 4, 9}}};

int init_prn_ca_gen(prn_ca_gen *gen, unsigned char prn);
void free_prn_ca_gen(prn_ca_gen *gen);
unsigned char prn_ca_gen_chip(prn_ca_gen *gen);

