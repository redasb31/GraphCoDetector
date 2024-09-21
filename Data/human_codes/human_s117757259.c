#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NUM 1000000007

int koyaku(int a,int b){
  if(a>b){
    if(a%b==0) return b;
    return koyaku(b,a-b);}
  else{
    if(b%a==0) return a;
    return koyaku(a,b-a);}
}

long int power(int a){ //2**a%NUM
  if(a<30) return (int)pow(2,a);
  long int tmp=(long int)pow(2,30)%NUM;
  return tmp*(a/30)*(int)pow(2,a%30);}

long int power2(int a,int b){
  long int mul=1;
  for(int i=0;i<b;i++){
    mul*=a;
    mul%=NUM;}
  return mul;}
  

long int disco(int h,int w,int t){
  if(t==1){
    long int sum=0;
    sum+=power2(2,h)%NUM;
    //printf("%ld\n",sum);
    sum+=power2(2,w)%NUM;
    //printf("%d\n",NUM);
    sum+=power2(2,koyaku(h,w));
    //printf("%ld\n",sum);
    return (sum-3)%NUM;}

  else{
    int koyaht=koyaku(h,t);
    int koyawt=koyaku(w,t);
    return (long int)power2(disco(h/koyaht,w/koyawt,1),koyaht*koyawt)%NUM;}
}

int main(){
  int h,w,t;
  scanf("%d%d%d",&h,&w,&t);
  long int sum=disco(h,w,t);
  printf("%ld\n",sum);
  return 0;
}
