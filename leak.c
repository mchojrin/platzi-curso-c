#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char * argv[] )
{
	char * p;

	for ( int i = 0; i < 10; i++ ) {
		printf( "%d - Alocando 50 chars\n", i );
		p = malloc(sizeof(char) * 50);
		sleep(1);
	}
	printf("Liberando p\n");
	printf( "Terminado!\n" );
}
