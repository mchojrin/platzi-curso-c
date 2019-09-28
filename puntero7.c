#include <stdio.h>

int main()
{
	int * pi;
	int a = 5;
	int b = 1;

	pi = &a;
	printf( "Antes\n\t a = %d, &a = %p, b = %d, &b = %p, p = %p\n", a, &a, b, &b, pi );
	pi++;
	*pi = 10;
	printf( "Despues\n\t a = %d, &a = %p, b = %d, &b = %p, p = %p\n", a, &a, b, &b, pi );
}
