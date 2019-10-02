#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( int argc, const char * argv[] )
{
	time_t oneDay = 24 * 60 * 60, today = time(NULL), nextDate;

	nextDate = today + oneDay * atoi( argv[1] ); 
	
	printf( "%s\n", ctime( &nextDate ) );
	
	return 0;
}
