#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int int_sort(const void *a, const void *b){
  if(*(int *)a < *(int *)b){
    return -1;
  }else if(*(int *)a == *(int *)b){
    return 0;
  }
  return 1;
}

int main(void){
  int n, h, ma=0, c=0, a[100000], b[100000], l, i;
  scanf("%d %d",&n, &h);
  l = h;
  for(i=0;i<n;i++){
    scanf("%d %d",&a[i],&b[i]);
    if(a[ma]<a[i] || (a[ma]==a[i] && b[ma]>=b[i])) ma = i;
  }
  for(i=0;i<n;i++) if(l>0 && i!=ma && b[i]>a[ma]){l-=b[i];  c++;}
  if(l<0){
    int sum=0;
    qsort((void *)b, n, sizeof(b[0]), int_sort);
    for(i=0;i<n;i++){
      sum+=b[i];
      if(sum>=h) break;
    }
    printf("%d\n",i+1);
  }else{
    //printf("l: %d  ma: %d c: %d\n",l,ma,c);
    l-=b[ma]; c++;
    if(l>0){
      c+=l/a[ma];
      if(l%a[ma]!=0) c++;
    }
    printf("%d\n",c);
  }
  return 0;
}
