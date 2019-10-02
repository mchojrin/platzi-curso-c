#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <unistd.h> 

int main( int argc, const char * argv[] )
{
	int pid = fork();

	if ( pid ) {
		printf( "Luke I am your father. Your PID is %d\n", pid );
	} else {
		printf( "I am Luke\n" );
	}

	while(1);

	return 0;
}
