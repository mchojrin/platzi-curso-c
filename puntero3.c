#include <stdio.h>

int main()
{
	int number = 10;
	int * pointToNumber = &number;

	printf("Step 0: pointer = '%p', number = '%d'\n", pointToNumber, number);
	(*pointToNumber)++;
	printf("Step 1: pointer = '%p', number = '%d'\n", pointToNumber, number);
	pointToNumber++;
	printf("Step 2: pointer = '%p', number = '%d'\n", pointToNumber, number);

	return 0;
}
