//To print series as 1, 4, 27,...

#include<stdio.h>
void main ()
{
	int counter, countOfterms, termCounter = 1, term;
	printf ("How many terms in the series 1, 4, 27,… do you want? ");
	scanf ("%d", &termCounter);
	term = termCounter;
	while (termCounter <= countOfterms)
	{
		for (counter = 1; counter <= termCounter; counter++)
		{
			term *= termCounter;
		}
		printf ("%d", term);
		if (counter != countOfterms)
		{
			printf (",");
		}
		else
		{
			printf (".");
		}
		termCounter += 1;
	}
}

