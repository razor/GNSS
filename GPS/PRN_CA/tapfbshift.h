
typedef struct shiftreg {
        unsigned char bits;
        unsigned int reg;
        unsigned char lock;
} shiftreg;

typedef struct tapsel {
        unsigned char tapsel_num;
        unsigned char taps_sel[2];
} tapsel;

void setepoch(shiftreg *sftreg, unsigned char numbits);
static unsigned char shift(shiftreg *sftreg);
static unsigned char getbit(shiftreg *sftreg, unsigned int bit);
unsigned char tapfbshift(shiftreg *sftreg, unsigned char tapcount, unsigned char *taps);
unsigned char tapfbshift_sel(shiftreg *sftreg, unsigned char tapcount, unsigned char *taps, tapsel sel);
