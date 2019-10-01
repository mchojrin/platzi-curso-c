#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, const char * argv[] )
{
	srand(time(NULL));
	printf( "%d\n", rand() );

	return 0;
}
