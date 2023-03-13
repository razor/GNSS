CC = gcc
CFLAGS = -g


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

testprn: testprn.o prn_ca.o tapfbshift.o
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
			
compile: testprn

.PHONY: clean

clean:
	rm -f *.o testprn
