#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
		char name[100];
		int age;
	} PERSON;

int main( int argc, const char * argv[] )
{
	PERSON person;

	if ( argc < 3 ) {
		printf( "Indique nombre y edad por favor\n" );

		return 1;
	}

	if ( strlen( argv[1] ) < 100 ) {
		strcpy( person.name, argv[1] );
	}
	person.age = atoi( argv[2] );
	
	printf( "Name = %s, age = %d\n", person.name, person.age );

	return 0;
}
