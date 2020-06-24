#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5  // number of bus stops (suppose bus have N=5)


int main()
{        
	unsigned int a[N];                     // num passengers exit bus
	unsigned int b[N], b_lim = 1000;       // num passenger enter bus, b <= b_lim
	unsigned int capacity;                 // output - minimum bus capacity 
	unsigned int temp = 0;                 // number of passengers in the bus

	int i;
	srand((unsigned int)time(0));

	for (i = 0; i < N; i++)
	{
		if (i == 0)                        // first stop
		{
			b[i] = rand() % (b_lim + 1);
			a[i] = 0;
			temp = b[i];
			capacity = temp;
			printf("Input: [(%1i , %1i), ", a[i], b[i]);
		}
		else if ( i == N - 1)             // last stop
		{
			a[i] = temp;
			b[i] = 0;
			printf("(%1i , %1i)] ", a[i], b[i]);
			printf("Output: %1i\n", capacity);
		}
		else                            // ith stop
		{
			a[i] = rand() % (temp);
			b[i] = rand() % (b_lim + 1);
			temp = temp - a[i] + b[i];

			printf("(%1i , %1i), ", a[i], b[i]);

			if (temp > capacity)
			{
				capacity = temp;
			}
		}
	}

	

}