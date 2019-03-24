#include <omp.h>
#include <stdlib.h>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char const *argv[]){
  int i, j, minimum;
  int x = 0;
  int y = 0;
  int dx = 1;
  int dy = 1;
  const char* imageName1 = argv[1];
  const char* imageName2 = argv[2];
  Mat image1;
  Mat image2;
  image1 = imread(imageName1, 1);
  image2 = imread(imageName2, 1);
  if(argc != 3 || !image1.data || !image2.data){
    printf("No image data \n");
    return -1;
  }

  Mat gray_image1;
  Mat gray_image2;
  
  cvtColor(image1, gray_image1, COLOR_BGR2GRAY);
  cvtColor(image2, gray_image2, COLOR_BGR2GRAY);
  
  int width = gray_image1.cols;
  int height = gray_image1.rows;
  int _stride = 15;

  int resh = (int)ceil(height/15);
  int resw = (int)ceil(width/15);
  
  int res[resh][resw];
  #pragma omp parallel
  {
    int i, j, x, y, suma, minimum;
    suma = 0;
    minimum = 0;
    int tid = omp_get_thread_num();
    for(x = 0; x < resh; x++){
      for(y = 0; y < resw; y++){
	#pragma omp for
	for(i = 0; i <= height ; i++){
	  for(j = 0; j <= width ; j++){
	   int mb1 = gray_image1.at<int>((x + i) * x * _stride, (y + j) * y * _stride);
	   int mb2 = gray_image2.at<int>((x + i + dx) * x * _stride, (y + j + dy) * y * _stride);
	   suma += abs(mb1 - mb2);
	   minimum = min(mb1, mb2);
	  }
	}
	if(suma == 0){
	  res[x][y] = 0;
	}else{
	  res[x][y] = minimum;
	}
	suma = 0;
        printf("%i ", res[x][y]);
      }
      printf("\n");
    }
  }
  
  return 0;
}
