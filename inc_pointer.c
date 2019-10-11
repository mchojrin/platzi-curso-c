#include <stdio.h>

int main()
{
	int a = 5;
	int * pi = &a;
	char c = 'A';
	char * pc;

	printf( "Antes pi = %p y pc = %p\n", pi, pc );
	pi++;
	pc++;
	printf( "Despues pi = %p, pc = %p\n", pi, pc );

	return 0;
}
