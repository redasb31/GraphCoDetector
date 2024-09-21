#include <stdio.h>
int main(){
  int N, i, j, k, ch = 0;
  int num[100];
  scanf("%d",&N);
  for( i = 0 ; i < N ; i++)
    scanf("%d",&num[i]);
  for(i = 0 ; i < N ; i++){
    for(j = N - 1 ; j >= i+1 ; j--){
      if(num[j] < num[j-1]){
	k = num[j];
	num[j] = num[j-1];
	num[j-1] = k;
	ch++;
      }
    }
  }
  printf("%d\n",ch);
  return 0;
}