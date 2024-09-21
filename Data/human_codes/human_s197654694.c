#include<stdio.h>

 int main(){
     int n,m,i,j;
     int a[100][100];
     int b[1000];
     int c[1000]={0};

     scanf("%d%d",&n,&m);
     for(i=0;i<n;i++){
           for(j=0;j<m;j++){
                scanf("%d",&a[i][j]);
                }
           }
     for(i=0;i<m;i++){
            scanf("%d",&b[i]);
            }
     for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                 c[i]+=a[i][j]*b[j];
                 }
            printf("%d\n",c[i]);
            }
     return 0;
     }

