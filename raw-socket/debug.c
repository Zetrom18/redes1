#include "main.h"

void debug_raw (unsigned char* r) {
	int i = 0;
	printf ("r[0]\tr[1]\tr[2]\tr[3]\n");
	printf ("%x\t%x\t%x\t%c\n", r[0], r[1], r[2], r[3]);

	printf ("r[4]: ");
	for (i = 0; i <= r[1] - 3; i++);
		printf ("%c", r[i + 4]);
	printf ("\n");

	printf ("r[%d]: %x\n", i + 4, r[i + 4]);
}
