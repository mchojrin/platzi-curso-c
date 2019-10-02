#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, const char * argv[] )
{
	FILE *in, *out;
	char buffer[100];

	if ( !(in = fopen( argv[1], "r" ) ) ) {
		printf("No pude leer el archivo %s\n", argv[1]);

		return -1;
	}

	if ( !(out = fopen( argv[2], "w" )) ) {
		printf("No puedo escribir en el archivo %s\n", argv[2] );
	}

	while ( fgets( buffer, 100, in ) != NULL ) {
		if ( strlen( buffer ) > atoi( argv[3] ) ) {
			fputs( buffer, out );
		}
	}

	fclose( in );
	fclose( out );
	 
	return 0;
}
