#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, const char * argv[] )
{
	time_t t = time(NULL);
	printf( "%s\n", ctime( &t ) );

	return 0;
}
