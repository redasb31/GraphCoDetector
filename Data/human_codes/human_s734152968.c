#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct linestruct{
  double a,b;
} line;

int cmpLine(const void *a,const void *b){
  double p=((line *)a)->a;
  double q=((line *)b)->a;
  return p-q>0?-1:1;
}

int calcInversion(double *a,int n,double *tmp){
  if(n<=1) return 0;
  int m=n/2;
  int res=calcInversion(a,m,tmp)+calcInversion(a+m,n-m,tmp);
  int i=0,j=m,k=0;
  while(i<m && j<n){
    if(a[i]<=a[j]){
      tmp[k++]=a[i++];
    } else {
      tmp[k++]=a[j++];
      res+=m-i;
    }
  }
  if(i<m) memcpy(tmp+k,a+i,sizeof(double)*(m-i));
  memcpy(a,tmp,sizeof(double)*(k+m-i));
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  line *l=(line *)calloc(n,sizeof(line));
  int i;
  for(i=0;i<n;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    l[i].a=-(double)a/b;
    l[i].b=(double)c/b;
  }
  qsort(l,n,sizeof(line),cmpLine);
  double *v=(double *)calloc(n,sizeof(double));
  double *tmp=(double *)calloc(n,sizeof(double));
  double ll=-200000000;
  double rr=200000000;
  for(int iter=0;iter<60;iter++){
    double m=(ll+rr)/2;
    for(i=0;i<n;i++) v[i]=l[i].a*m+l[i].b;
    int inv=calcInversion(v,n,tmp);
    if(2*inv<n*(n-1)/2){
      ll=m;
    } else {
      rr=m;
    }
  }
  double ansX=ll;
  for(i=0;i<n;i++){
    double a=l[i].a;
    double b=l[i].b;
    l[i]=(line){1/a,-b/a};
  }
  qsort(l,n,sizeof(line),cmpLine);
  ll=-200000000;
  rr=200000000;
  for(int iter=0;iter<60;iter++){
    double m=(ll+rr)/2;
    for(i=0;i<n;i++) v[i]=l[i].a*m+l[i].b;
    int inv=calcInversion(v,n,tmp);
    if(2*inv<n*(n-1)/2){
      ll=m;
    } else {
      rr=m;
    }
  }
  double ansY=ll;
  printf("%.9lf %.9lf\n",ansX,ansY);
}

int main(void){
  run();
  return 0;
}
