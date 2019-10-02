#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct person {
	char name[100];
	unsigned char age;
};

int main( int argc, const char * argv[] )
{
	FILE *out;
	char buffer[100];

	if ( argc < 2 ) {
		printf("Indique el nombre del archivo de salida\n");

		return -1;
	}
	if ( !(out = fopen( argv[1], "w" )) ) {
		printf("No puedo escribir en el archivo %s\n", argv[1] );

		return -2;
	}

	struct person p;

	do {
		printf("Ingrese el nombre de la persona: ");
		scanf("%100s", p.name);
		printf("Ingrese la edad de la persona: ");
		scanf("%d", &p.age);
		fwrite( &p, sizeof( struct person ), 1, out );
		printf("Grabada! Otra?(S/N): ");
		scanf("%1s", buffer );
	} while ( tolower( buffer[0] ) != 'n' );
	
	fclose( out );
	printf("Archivo de personas grabado!\n");
	 
	return 0;
}
