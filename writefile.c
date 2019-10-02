#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, const char * argv[] )
{
	FILE *out;
	char buffer[100];

	if ( !(out = fopen( argv[1], "w" )) ) {
		printf("No puedo escribir en el archivo %s\n", argv[1] );
	}

	do {
		printf("Ingrese una palabra: ");
		scanf("%100s", buffer);
		fputs( buffer, out );
		fputs( "\n", out );
		printf("Grabada! Otra?(S/N): ");
		scanf("%1s", buffer );
	} while ( tolower( buffer[0] ) != 'n' );
	
	fclose( out );
	 
	return 0;
}
