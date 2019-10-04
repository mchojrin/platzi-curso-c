#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main( int argc, const char * argv[] )
{
	int pid = fork();
	int shared = 2;

	if ( pid ) {
		shared = 1;
		printf( "Luke I am your father. My PID is %d and your PID is %d, shared = %d\n", getpid(), pid, shared );
		wait( NULL );
		printf( "This is your father again, shared = %d\n", shared );
	} else {
		printf( "I am Luke. My PID is %d. shared = %d. I'll set shared = 0 and go sleep...\n", getpid(), shared );
		shared = 0;
		sleep(2);
		printf( "I am Luke, just woke up. shared = %d. Bye!\n", shared);
	}

	return 0;
}
