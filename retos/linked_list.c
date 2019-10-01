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

void releaseNodes( NODE ** start, int number )
{
	NODE *current, *previous;

	if ( *start ) {
		printf( " 1. Eliminando los numeros %d del comienzo de la lista\n", number );
		while ( (*start) && (*start)->number == number ) {
			printf( " 1.a. Un nodo eliminado\n" );
			NODE * aux = (*start)->next;
			free ( *start );
			*start = aux;
		}

		previous = *start;
		current = previous->next;
		printf( " 2. Eliminando los numeros %d del resto de la lista\n", number );
		while ( current ) {
			if ( current->number == number ) {
				printf( " 2.a. Encontre un %d, elimino\n", number );
				previous->next = current->next;
				free( current );
				current = previous->next;
			} else {
				printf( " 2.a. Encontre un %d, salteo\n", current->number );
				previous = current;
				current = current->next;
			}	
		}
	}
}

void printList( NODE * start)
{
	NODE * current = start;
	printf( "\nLa lista contiene los siguientes numeros: " );
	while ( current ) {
		printf( "%d", current->number );
		printf( current->next ? ", " : "\n" );
		current = current->next;
	}
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

	printList( start );

	printf( "Ingrese numero quiere eliminar:" );
	int deleteNumber;
	scanf("%d", &deleteNumber );

	printf( "Eliminando los nodos con el numero %d\n", deleteNumber );
	releaseNodes( &start, deleteNumber );
	printf( "Eliminados!" );

	printList( start );

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
