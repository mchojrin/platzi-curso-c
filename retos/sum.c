#include <stdio.h>

int main()
{
	int num1, num2;
	printf( "Ingrese el primer numero\n" );
	scanf("%d", &num1);

	printf( "Ingrese el segundo numero\n" );
	scanf("%d", &num2);

	printf( "%d + %d = %d\n", num1, num2, num1 + num2 );

	return 0;
}
