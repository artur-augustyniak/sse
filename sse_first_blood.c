#include <stdio.h>
#include <string.h>
#include <emmintrin.h>

#define N 1000000

int main(void)
{
	/*int a[N];
    memset(a, -1, N *  sizeof(int));
	
	long int sum = 0;

*/
	int a[4] = {1,2,3,4};
	__m128i* sse_a = (__m128i*)a;

	int b[4] = {1,2,3,4};
	__m128i* sse_b = (__m128i*)b;

	__m128i sum = _mm_add_epi32(*sse_a, *sse_b);

	int* res = (int*)&sum;
	for(int i = 0; i < 4; i++)
		printf("%i\n", res[i]);


/*	
	for(int i = 0; i < N; i++)
	{
		sum +=a[i];
	}
 
	printf("Suma: %i\n", sum);*/
	return 0;
}
