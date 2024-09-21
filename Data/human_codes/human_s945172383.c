#include <stdio.h>
#include <math.h>
int main(){
  int i, test[5], sum = 0, average = 0;
  for(i = 0;i < 5;i++){
    scanf("%d", &test[i]);
    if(test[i] < 40){
      test[i] = 40;
    }
    sum += test[i];
  }
  average = round((double)sum / 5);
  printf("%d\n", average);
  return 0;
}