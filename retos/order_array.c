#include <stdio.h>

void print_array( int * array )
{
	printf( "a = [") ;
	for ( int i = 0; i < 9; i++ ) {
		printf( "%d, ", array[i] );
	}
	printf( "%d ]\n", array[9] );
}

int main()
{
	int array[10], i, j;

	for ( i = 0; i < 10; i++ ) {
		printf( "Ingrese un numero\n" );
		scanf( "%d", array + i );
	}

	print_array( array );
	for ( i = 0; i < 10; i++ ) {
		for ( j = 0; j < 9; j++ ) {
			if ( array[j] > array[j + 1] ) {
				int aux = array[j];
				array[j] = array[ j + 1];
				array[j + 1] = aux;
				print_array( array );
			}
		}
	}

	print_array( array );
}
