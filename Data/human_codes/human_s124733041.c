#include<stdio.h>
#include<math.h>
int main() {
  float x1, x2, y1, y2, result;


  scanf("%f %f %f %f", &x1, &x2, &y1, &y2);
  result = sqrt((y1 - x1) * (y1 - x1) + (y2 - x2) * (y2 - x2));
  printf("%.8f\n", result);
     
  return 0;
}