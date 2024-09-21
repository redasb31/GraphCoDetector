#include <stdio.h>

#define N 8
#define TRUE 1
#define FALSE 0
#define CHECKED 1
#define NOT_CHECKED -1

int tate[N];
int yoko[N];
int naname_l[2*N-1];
int naname_r[2*N-1];
int hi[N][N];

void reset();
void print();
void recursive (int st);

int main(){
  int i,j,k,tate,yoko;
  reset();

  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      hi[i][j]=FALSE;
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d%d",&tate,&yoko);
    hi[tate][yoko]=TRUE;
  }

  recursive(0);

  return 0;
}

	
  
void reset(){
  int i;
  for(i=0;i<N;i++){
    tate[i]=NOT_CHECKED,
      yoko[i]=NOT_CHECKED;
  }

  for(i=0;i<2*N-1;i++){
    naname_l[i]=NOT_CHECKED;
    naname_r[i]=NOT_CHECKED;
  }
}

void print(){
  int i,j;
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(hi[i][j]){
	if(tate[i]!=j)
	  return;
      }
    }
  }

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(tate[i]==j){
	printf("Q");
      }else{
	printf(".");
      }
    }
    printf("\n");
  }
}
      
void recursive (int st){
  int i;
  if(st==N){
    print();
    return;
  }

  for(i=0;i<N;i++){

    if(CHECKED==yoko[i] ||CHECKED==naname_l[st+i] ||CHECKED==naname_r[st-i+N-1])
      continue;

    tate[st]=i;
    yoko[i]=naname_l[st+i]=naname_r[st-i+N-1]=CHECKED;

    recursive(st+1);

    tate[st]=yoko[i]=naname_l[st+i]=naname_r[st-i+N-1]=NOT_CHECKED;
  }
}

    


