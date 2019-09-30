#include <stdio.h>
#include <string.h>

int main( int argc, const char * argv[] )
{
	int i, maxLen = strlen( argv[1] );
	const char * longest = argv[1];

	for ( i = 2; i < argc; i++ ) {
		if ( strlen( argv[i] ) > maxLen ) {
			longest = argv[i];
			maxLen = strlen( argv[i] );
		}
	}

	printf( "La mas larga es: %s (%d caracteres)\n", longest, maxLen );
}
