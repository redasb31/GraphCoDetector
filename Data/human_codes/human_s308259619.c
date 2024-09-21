#include <stdio.h>
#include <stdlib.h>

int bin_search(int a[], int num,float key);

int main(){
  int N,i;	
  int sum = 0;
  float avr;
  int *a;
  scanf("%d",&N);
 
  a = (int *)calloc(N,sizeof(int));
  for(i = 0;i < N;i++){
  	scanf("%d",&a[i]);
    sum += a[i];
  }
  avr = sum / N;
  printf("%d\n",bin_search(a,N,avr));
  
  free(a);
  return 0;
}

int bin_search(int a[], int num,float key){
  int pc = 0;
  int pr = num-1;
  int tmp = 1024;
  int disc;
  int min = 1024;
  while(pc <= pr){
    disc = abs(a[pc]*num - key*num);
    if(min > disc) {
      min = disc;
	  tmp = pc;
    }
    if(min == disc){
	  if(tmp > pc){
	    min = disc;
	    tmp = pc;
	  }
	}
    pc++;
  }
  return tmp;
}