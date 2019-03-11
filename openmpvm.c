#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i, j, x, y;
    int dx = 0;
    int dy = 0:
    int val = 10000;
	srand(time(NULL));
	//int n = atoi(argv[1]);
    int n = 16;
	int vector__1[n][n], vector__2[n][n], vector__res[n][n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			vector__1[i][j] = (rand()%4)+1;
			vector__2[i][j] = (rand()%4)+1;
		}
	}
	#pragma omp parallel
	{
		int tid;
		int i, j, k, suma = 0;
		tid = omp_get_thread_num();
		#pragma omp for 
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
			    suma = (vector__1[x + i][y + y] - vector__2[x + i + dx][y + j + dy]);
				if(val < suma){
                    val = suma;
                }
			}
		}
	}
    // Print val pero no se como Xd
	return 0;
}