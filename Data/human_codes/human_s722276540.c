#include<stdio.h>
#include<stdlib.h>
struct DAta{
  char s[21];
  double a;
}d[50];

int cmp(const void *a,const void *b){
  struct DAta f,e;
  f=*(struct DAta *)a;
  e=*(struct DAta *)b;
  if(f.a==e.a)return strcmp(f.s,e.s);
    return f.a=e.a;
}


int main(void){
  int n,i,j;
  int p,s,m,a,b,c,d,e,f;
  
  while(scanf("%d",&n),n){
  for(i=0;i<n;i++){
    scanf("%s%d%d%d%d%d%d%d%d%d",d[i].s,&p,&a,&b,&c,&d,&e,&f,&s,&m);
    d[i].a=((double)f*m*s-p)/(a+b+c+d+e);
  }
  qsort(d,n,sizeof(struct DAta),cmp);
  for(i=0;i<n;i++){
    printf("%s\n",d[i].s);
  }
  puts("#");
  }
  return 0;}