#include <stdio.h>

int main()
{
	int number = 10;
	int * pointToNumber = &number;

	printf("Pointer = '%p', number = '%d', *pointer = '%d'\n", pointToNumber, number, *pointToNumber);
	return 0;
}
