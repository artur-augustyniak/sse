#include <stdio.h>
#include <string.h>

#define N 1000000

int main(void)
{
	int a[N];
    memset(a, -1, N *  sizeof(int));
	
	long int sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum +=a[i];
	}
 
	printf("Suma: %i\n", sum);
	return 0;
}
