#include <stdio.h>

int main()
{
	int number;
	int * pointToNumber = &number;

	printf("%p", pointToNumber);
}
