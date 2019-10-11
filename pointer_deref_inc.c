#include <stdio.h>

int main()
{
	int number = 10;
	int * pointToNumber = &number;

	printf(" 1 - Pointer = '%p', number = '%d', *pointer = '%d'\n", pointToNumber, number, *pointToNumber);
	(*pointToNumber)++;
	printf(" 2 - Pointer = '%p', number = '%d', *pointer = '%d'\n", pointToNumber, number, *pointToNumber);

	return 0;
}
