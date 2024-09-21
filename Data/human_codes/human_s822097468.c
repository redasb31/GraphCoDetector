#include<stdio.h>

int compare(int a,int b);

int main()
{
  int N,A,B;
  int X,x,ans;

  scanf("%d",&N);
  scanf("%d",&A);
  scanf("%d",&B); 

  if(A > B){
    x = B;
    X = A;
  }
  else{
    x = A;
    X = B;
  }

  if((X - x)%2 == 0){
    ans = (X - x)/2;
  }
  else{   
    //ans = compare(N - x,X - 1,((N - x) + (N - X) + 1)/2);
    if(N - x > X - 1){
      ans = compare(X - 1,((x - 1) + (X - 1) + 1)/2);
    }
    else{
      ans = compare(N - x,((N - x) + (N - X) + 1)/2);
    }
      
  }

  
  printf("%d\n",ans);
  
  
  return 0;
}

int compare(int a,int b){
  if(a > b){
      return b;
  }
  else{
    return a;
  }
}
