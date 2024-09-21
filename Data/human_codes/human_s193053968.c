#include<stdio.h>

void swap(int A[],int a,int b){
int temp;
temp=A[a];
A[a]=A[b];
A[b]=temp;

return;
}


int getGCM(int x,int y){
int a,b;

 if(x%y==0)return y;
 else{
  b=x%y;
  a=getGCM(y,b);
 }

}



int getLCM(int x,int y){
int gcm;
int lcm;

gcm=getGCM(x,y);

lcm=x*y/gcm;

return lcm;
}


int main(){
int n,i,j;
int A[10];


scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&A[i]);

for(i=0;i<n;i++){
 for(j=0;j<n-i-1;j++){
   if(A[j]<A[j+1])swap(A,j,j+1);
   A[j]=getLCM(A[j],A[j+1]);
 }
}
 
printf("%d\n",A[0]);

return 0;
}
