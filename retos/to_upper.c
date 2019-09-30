#include <stdio.h>
#include <string.h>

int main( int argc, const char * argv[])
{
	if ( argc < 2 ) {
		printf( "Pasame argumentos man!");		

		return -1;
	}
	
	int diff = 'a' - 'A';

	printf( "Original = %s\n", argv[1] );
	printf( "Diff = %d\n", diff );

	for ( int i = 0; i < strlen( argv[1] ); i++ ) {
		printf( "%c", argv[1][i] <= 'Z' ? argv[1][i] : argv[1][i] - diff );
	}

	printf("\n");
}
