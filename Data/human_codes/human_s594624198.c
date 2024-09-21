#include <stdio.h>
#include <stdlib.h>

int culc_time(int [][3], int, int, int, int);

int main(){
  int i, n, t, var = 0, count = 0, len;
  if (scanf("%d %d", &n, &t) == EOF){
    exit(1);
  }
  int array[n][3];
  for (i = 0; i < n; i++){
    if (scanf("%d %d", &array[i][0], &array[i][1]) == EOF){
      exit(1);
    }
    array[i][2] = 0;
  }
  len = sizeof(array) / (sizeof(int) * 3);
  printf("%d", culc_time(array, t, var, len, count));
  return 0;
}

int culc_time(int a[][3], int t, int var, int len, int count){
  int i;
  if (var > t){
    return 0;
  }else{
    if (count == 0){
      for (i = 0; i < len; i++){
        if (a[i][2] == 0){
          var = var * a[i][0] + a[i][1];
          a[i][2] = 1;
          count = 1;
          return culc_time(a,t,var,len,count) + 1;
        }
      }
    }else{
      int tmp, min, c = 0;
      for (i = 0; i < len; i++){
        if (a[i][2] == 0){
          tmp = var * a[i][0] + a[i][1];
          a[i][2] = 1;
          if (c == 0){
            min = tmp;
            c = 1;
          }else{
            if (min > tmp){
              min = tmp;
            }
          }
        }
      }
      return culc_time(a,t,min,len,count) + 1;
    }
  }
}
