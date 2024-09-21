#include <stdio.h>
int main(void){
  int n,q;
  scanf("%d",&n); 
  int a[n];
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(int i=0;i<q;i++){
      int b,e,com,x=0,y;
      scanf("%d %d %d",&com,&b,&e);
      x=a[b];
      
          for(int j=b;j<e;j++){
              
              if(com==0){
              if(x>a[j]){
                  y=x; x=a[j]; 
              }
              }
              else {
                  if(x<a[j]){
                      y=x; x=a[j];
                  }
              }
          }
          printf("%d\n",x);
        
      }
   return 0;
    }

