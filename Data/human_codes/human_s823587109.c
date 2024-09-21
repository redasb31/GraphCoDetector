#include<stdio.h>
#include<math.h>

int main(){

     int n,a[100],i,dice=1,temp=0;

     scanf("%d",&n);

     for(i=0;i<n;i++){
       scanf("%d",&a[i]);
       temp = temp + a[i];
       if(temp==1 && a[i]==1) dice = dice + 1;
       else if(a[i-1]==1 && a[i]==1) dice = dice + 1;
     }

     printf("%d\n",dice);

     return 0;

}
        
