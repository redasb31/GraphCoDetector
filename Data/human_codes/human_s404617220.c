#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  int *a=(int *)malloc(sizeof(int)*h*w);
  int i;
  for(i=0;i<h*w;i++) scanf("%d",a+i);
  int *way=(int *)malloc(sizeof(int)*4*h*w);
  int wlen=0;
  int cnt=0;
  for(i=0;i<h*w;i++) cnt+=a[i]%2;
  cnt/=2;
  for(i=0;i<h && cnt>0;i++){
    int flag=0;
    int j=0;
    while(j<w && cnt>0){
      if(a[POS(i,j)]%2){
	if(flag) cnt--;
	flag^=1;
      }
      if(flag && cnt>0 && j+1<w){
	way[4*wlen+0]=i+1;
	way[4*wlen+1]=j+1;
	way[4*wlen+2]=i+1;
	way[4*wlen+3]=j+2;
	wlen++;
      }
      j++;
    }
    if(flag) a[POS(i,w-1)]=1;
  }
  i=0;
  int j=w-1;
  int flag=0;
  while(i<h && cnt>0){
    if(a[POS(i,j)]%2){
      if(flag) cnt--;
      flag^=1;
    }
    if(flag && cnt>0){
      way[4*wlen+0]=i+1;
      way[4*wlen+1]=j+1;
      way[4*wlen+2]=i+2;
      way[4*wlen+3]=j+1;
      wlen++;
    }
    i++;
  }
  printf("%d\n",wlen);
  for(i=0;i<wlen;i++){
    printf("%d %d %d %d\n",way[4*i+0],way[4*i+1],way[4*i+2],way[4*i+3]);
  }
}

int main(void){
  run();
  return 0;
}
