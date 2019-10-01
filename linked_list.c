#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

int main( int argc, const char * argv[] )
{
	NODE * start, * current = NULL;
	char goOn;
	int listSize = 0, number;
	
	do {
		printf( "La lista contiene %d nodos. Ingrese el siguiente numero (0 para finalizar): ", listSize );
		scanf("%d", &number);
		if ( number ) {
			NODE * newNode = malloc( sizeof( NODE ) );
			newNode->number = number;
			newNode->next = NULL;
			if ( listSize++ ) {
				current->next = newNode;
				current = newNode;
			} else {
				start = current = newNode;
			}
		}
	} while ( number );

	current = start;
	printf( "La lista contiene los siguientes numeros: " );
	while ( current ) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}

	current = start;

	NODE * next;
	while ( current ) {
		next = current->next;
		free(current);
		current = next;
	}

	printf("Todo liberado!\n");

	return 0;
}
