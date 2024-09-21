#include<stdio.h>
#include<stdlib.h>
 
int main(void){
  struct{
    int start;
    int goal;
    int flg;
  }prof[100];
  int sum=0;
  int n,m,a,b;
  int i,j,k,who,whol;
 
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    prof[i].start=a-1;
    prof[i].goal=b-1;
    prof[i].flg=0;
  }
  
  for(i=0;i<n;i=whol+1){
    who=-1;
    whol=-1;
    for(j=0;j<m;j++){
      if(i<prof[j].start || i>prof[j].goal) continue;
      if(whol<prof[j].goal){
	who=j;
	whol=prof[j].goal;
      }
    }
    if(who==-1){
      puts("Impossible");
      return 0;
    }
    prof[who].flg=1;
  }
    
  for(i=0;i<m;i++) sum+=prof[i].flg;
  printf("%d\n",sum);
  return 0;
}