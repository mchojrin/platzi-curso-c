#include <stdio.h>
#include <string.h>

int main()
{
	char * src = "Mauro";
	char dst[20] = "No veras esto nunca!";

	strcpy( dst, src );
	printf( "dst = %s\n", dst );

	return 0;
}
