#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

void addNode( NODE ** start, NODE * newNode ) 
{
	if ( *start ) {
		NODE * current = *start;
		while ( current->next ) {
			current = current->next;
		}

		current->next = newNode;
	} else {
		*start = newNode;
	}
}

NODE * createNode( int number )
{
	NODE * newNode;
	
	newNode = malloc( sizeof( NODE ) );
	newNode->next = NULL;
	newNode->number = number;

	return newNode;
}

int main( int argc, const char * argv[] )
{
	NODE * start = NULL, * current;
	char goOn;
	int listSize = 0, number;
	
	do {
		printf( "La lista contiene %d nodos. Ingrese el siguiente numero (0 para finalizar): ", listSize );
		scanf("%d", &number);
		if ( number ) {
			addNode( &start, createNode( number ) );
		}
	} while ( number );

	current = start;
	printf( "\nLa lista contiene los siguientes numeros: " );
	while ( current ) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}

	current = start;

	NODE * next;
	while ( current ) {
		printf( "Liberando el nodo %d\n", current->number );
		next = current->next;
		free(current);
		current = next;
	}

	printf("Todo liberado!\n");

	return 0;
}
