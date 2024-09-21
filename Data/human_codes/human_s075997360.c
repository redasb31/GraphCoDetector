#include <stdio.h>
#include <stdlib.h>
int main(){
       int n,m,start,end;
       scanf("%d%d",&n,&m);
       int a[200000]={0},b[200000]={0};
       int counta=0,countb=0;
       for(int i=0;i<m;i++){
              scanf("%d%d",&start,&end);
              if(start==1&&end!=n)  b[countb++]=end;
              if(end==n&&start!=1) a[counta++]=start;
       }
       int flag=0;
       for(int i=0;i<counta;i++){
              for(int j=0;j<countb;j++){
                     if(a[i]==b[j]){
                            printf("POSSIBLE");
                            flag=1;
                            break;
                     }
              }
       }
       if(flag==0) printf("IMPOSSIBLE");
       return 0;
}
