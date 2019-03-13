#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cxtypes.h>



int main(int argc, char const *argv[])
{
	int i, j;
	int x = 0;
	int y = 0;
    int dx = 1;
    int dy = 1;
    int val = 10000;
	srand(time(NULL));
	//int n = atoi(argv[1]);
    int n = 16;
	int vector__1[n][n], vector__2[n][n];
	IplImage* img = cvLoadImage( "controller.png" );
 	cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
 	cvShowImage("Example1", img);
 	cvWaitKey(0);
 	cvReleaseImage( &img );
 	cvDestroyWindow( "Example1" );
 return 0;for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			//(rand()%4)+
			vector__1[i][j] = 1;
			vector__2[i][j] = 1;
		}
	}
	
	#pragma omp parallel
	{
		int i, j,  suma = 0;
		tid = omp_get_thread_num();
		#pragma omp for 
		for(i = 0; i <= n ; i++)
		{
			for(j = 0; j <= n ; j++)
			{
			    suma = (vector__1[x + i][y + j] - vector__2[x + i + dx][y + j + dy]);
				if(val > suma){
                    val = suma * - 1;
                }
			}
		}
		printf("Estamos en el thread %d\n", tid);
		printf("El valor da %d\n", val);
	}
 	return 0;
}
