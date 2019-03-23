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
  uint8_t *myData1 = gray_image1.data;
  uint8_t *myData2 = gray_image2.data;
  int width = gray_image1.cols;
  int height = gray_image1.rows;
  int _stride = image1.step;
  srand(time(NULL));
  int vector__1[height][width], vector__2[height][width];
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++){
      uint8_t val1 = myData1[i * _stride + j];
      uint8_t val2 = myData2[i * _stride + j];
      vector__1[i][j] = val1;
      vector__2[i][j] = val2;
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
