#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char const *argv[]){
  int i, j;
  int x = 0;
  int y = 0;
  int dx = 1;
  int dy = 1;
  int val = 10000;
  const char* imageName = argv[1];
  Mat image;
  image = imread(imageName, 1);
  if(argc != 2 || !image.data){
    printf("No image data \n");
    return -1;
  }
  Mat gray_image;
  cvtColor(image, gray_image, COLOR_BGR2GRAY);
  uint8_t *myData = gray_image.data;
  int width = gray_image.cols;
  int height = gray_image.rows;
  int _stride = image.step;
  srand(time(NULL));
  //int n = atoi(argv[1]);
  int vector__1[height][width], vector__2[height][width];
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++){
      uint8_t val = myData[i * _stride + j];
      vector__1[i][j] = val;
      vector__2[i][j] = val;
    }
  }
  #pragma omp parallel
  {
    int i, j,  suma = 0;
    int tid = omp_get_thread_num();
  #pragma omp for
    for(i = 0; i <= height ; i++){
      for(j = 0; j <= width ; j++){
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
