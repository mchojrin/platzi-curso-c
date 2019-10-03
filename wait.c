#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main( int argc, const char * argv[] )
{
	int pid = fork();

	if ( pid ) {
		printf( "Luke I am your father. My PID is %d and your PID is %d\n", getpid(), pid );
		wait( NULL );
		printf( "This is your father again" );
	} else {
		printf( "I am Luke. My PID is %d and now I'm going to sleep...\n", getpid() );
		sleep(2);
	}

	return 0;
}
