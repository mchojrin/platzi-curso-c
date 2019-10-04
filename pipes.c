#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 16

int main( int argc, const char * argv[] )
{
	FILE * in;
	int pid, p[2];
	
	if ( pipe(p) < 0 ) {

		return -2;
	}

	if ( !( in = fopen( argv[1], "r" ) ) ) {
		
		return -1;
	}
	
	if ( pid = fork() ) {
		char buffer[MSGSIZE];
		printf( "++ I am the father process. Child PID = %d. Reading from %s\n", pid, argv[1] );
		while ( fgets( buffer, MSGSIZE, in ) ) {
			printf( "  ++ Read '%s'. %d what's the max character?\n", buffer, pid );
			write( p[1], buffer, MSGSIZE );
		}
		close( p[1] );
		printf("++ Waiting for my children\n");
		wait(NULL);	
		printf("++ All children done\n");
		fclose(in);
	
	} else {
		close(p[1]);
		printf( "-- I am the child. Waiting for lines to appear in the pipe\n" );
		char buffer[MSGSIZE], max;

		while( read(p[0], buffer, MSGSIZE) > 0) {
			printf( "-- Read '%s' from the pipe\n", buffer);
			max = buffer[0];
			for ( int i = 0; i < MSGSIZE; i++ ) {
				if ( buffer[i] > max ) {
					max = buffer[i];
				}
			}	
			printf(" -- Max = '%c'\n", max);
		}
	}
	 
	return 0;
}
