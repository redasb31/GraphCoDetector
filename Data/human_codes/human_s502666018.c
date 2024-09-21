#include<stdio.h>
int main(void){
     int a,b,c,i=7;
     while(i!=0){
           scanf("%d %d",&a,&b);
           c=-1*(-1*a--1*b);
           printf("%d\n",c);
     }
     return 0;
}