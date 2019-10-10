int main()
{
	int n = 1, acum = 10;

	do {
		acum += n;
		n++;
	} while ( acum < 10 );	

	return acum;
}
