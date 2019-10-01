#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char NAME[100];
typedef char EMAIL[100];

typedef struct {
	NAME name;
	EMAIL email;
} CONTACT;

int main( int argc, const char * argv[] )
{
	CONTACT * list = NULL;
	char buffer[100];
	int goOn, listSize = 0;

	do {
		printf( "Ingrese el nombre del nuevo contacto (0 para terminar): ");
		scanf( "%99s", buffer );
		if ( ( goOn = strcmp( "0", buffer ) ) ) {
			if ( !list ) {
				list = malloc( sizeof( CONTACT ) );
			} else {
				list = realloc( list, sizeof( CONTACT ) * ( listSize + 1 ) );
			}
			strcpy( list[ listSize ].name, buffer );
			printf( "Ingrese el email de %s: ", buffer );
			scanf( "%99s", buffer );
			strcpy( list[ listSize ].email, buffer );
			listSize++;
			
		}
	} while ( goOn );

	printf( "\nEsta es tu lista de contactos:\n" );

	printf("Nombre\t\tEmail\n");
	printf("------\t\t-----\n");
	for ( int i = 0; i < listSize; i++ ) {
		printf( "%s\t\t%s\n", list[i].name, list[i].email );
	}

	char answer[2];
	int doDelete;

	do {
		printf( "Quiere eliminar el ultimo contacto? (S/N) ");
		scanf( "%1s", answer );
		if ( doDelete = ( strcmp( "S", answer ) == 0 || strcmp( "s", answer ) == 0 ) ) {
			list = realloc( list, sizeof( CONTACT ) * listSize-- );
		}
	} while ( doDelete && listSize > 0 );

	printf( "\nEsta es tu lista de contactos:\n" );

	printf("Nombre\t\tEmail\n");
	printf("------\t\t-----\n");
	for ( int i = 0; i < listSize; i++ ) {
		printf( "%s\t\t%s\n", list[i].name, list[i].email );
	}
	free( list );
	return 0;
}
