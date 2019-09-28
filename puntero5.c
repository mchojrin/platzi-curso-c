#include <stdio.h>

int main()
{
	int a = 5;
	int * p = &a;

	printf( "Antes p = %p\n", p );
	p++;
	printf( "Despues p = %p\n", p );
}
