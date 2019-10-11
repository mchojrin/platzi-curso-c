#include <stdio.h>

int main()
{
	char * name = "Mauro";

	printf("Nombre = %s (%p) \n", name, name);

	for ( int i; i < 5; i++ ) {
		printf( "name[%d](%p) = %c\n", i, name + i, name[i] );
	}
}
