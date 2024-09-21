#include<stdio.h>

int cnt(int n, int a[]){
   int i = 0;
    while(a[0] && a[1] && a[2])
    {
      i = i +1;        
    }
    return i;
}

int main (void){
    int n;
    scanf("%d",&n);
    int a[n];
    scanf("%d",&a);
    int ans = cnt(n,a);
    printf("%d",ans);
    return 0;
}