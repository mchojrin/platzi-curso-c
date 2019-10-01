#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char PASSPORT[15];
typedef char PHONE_NBR[15];

typedef struct {
		char name[100];
		int age;
		PASSPORT passport;
		PHONE_NBR phone;
	} PERSON;

void fillPersonData( PERSON * person, const char * name, int age )
{
	if ( strlen( name ) < 100 ) {
		strcpy( person->name, name );
	}
	person->age = age;
}

int main( int argc, const char * argv[] )
{
	PERSON person;

	if ( argc < 3 ) {
		printf( "Indique nombre y edad por favor\n" );

		return 1;
	}

	fillPersonData( &person, argv[1], atoi( argv[2] ) );	
	printf( "Name = %s, age = %d\n", person.name, person.age );

	return 0;
}
