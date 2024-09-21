#include<stdio.h>
void solve(void);
void print(void);
void clear(void);

int n,dat[1000]={0};
int main(){

  while(1){

  scanf("%d",&n);
  
  if(n==0){
    break;
  }

  printf("%d\n",n);

  dat[0]=n;

  solve();

  clear();

  }

  return 0;
}

  void solve(){

    int kt=2;

    while(1){

      if(dat[0]==1){
	break;
      }

      else if(dat[1]==2){
	dat[kt]=1;
	kt++;
	dat[1]--;
      }
      
      else if(dat[0]==2 && dat[1]==1){
	dat[kt]=1;
	dat[0]=1;
      }

      else if(dat[1]==0 || dat[1]==1){
	dat[0]--;
	dat[1]++;
      }


  print();

    }

  }

void print(){

  int i;

  i=0;
  while(dat[i]!=0){
    printf("%d",dat[i]);
    if(dat[i+1]!=0){
      printf(" ");
    }
    i++;
  }

  printf("\n");

}

void clear(){

  int i;

  for(i=0;i<n;i++){

    dat[i]=0;
  }

}