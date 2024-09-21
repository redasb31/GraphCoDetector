#include <stdio.h>

int main(void){
  int q;
  scanf("%d",&q);
  int A[800010];
  int start=400000;
  int last=400001;
  int command;
  int d,x,p;
  for(int i=0;i<q;i++){
    scanf("%d",&command);
    if(command==0){
      scanf("%d %d",&d,&x);
      if(d==0){
        A[start]=x;
        start--;
      }
      else{
        A[last]=x;
        last++;
      }
    }
    else if(command==1){
      scanf("%d",&p);
      printf("%d\n",A[p+start+1]);
    }
    else if(command==2){
      scanf("%d",&d);
      if(d==0){
        start++;
      }
      else{
        last--;
      }

    }
  }
  return 0;
}

