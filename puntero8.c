#include <stdio.h>

int main()
{
	int b = 1;
	int a[5];
	
	printf( "Antes\n\t b = %d\n", b );
	int ib;
	for ( int i = -5; i < 5; i++ ) {
		if ( a + i == &b ) {
			ib = i;
			printf( "&b = a[%d]\n", i);
		}
	}
	a[ib] = 8;
	printf( "Despues\n\t b = %d\n", b );
}
