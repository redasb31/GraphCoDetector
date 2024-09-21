#include<stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

#define F 6

double winPetr(double p,double *a,double *b){
  const double min=0.001;
  double win=0;
  int i;
  for(i=0;i<F;i++){
    if(a[i]<=min && b[i]<=min) continue;
    double t=p*a[i]+(1-p)*b[i];
    win+=t*MIN(p*a[i]/t,(1-p)*b[i]/t);
  }
  return win;
}

void run(void){
  double p[F],q[F];
  int i;
  for(i=0;i<F;i++){
    int v;
    scanf("%d",&v);
    p[i]=(double)v/100;
  }
  for(i=0;i<F;i++){
    int v;
    scanf("%d",&v);
    q[i]=(double)v/100;
  }
  double l=0;
  double r=1;
  for(i=0;i<100;i++){
    double ll=(2*l+r)/3;
    double fl=winPetr(ll,p,q);
    double rr=(l+2*r)/3;
    double fr=winPetr(rr,p,q);
    if(fl<=fr){
      l=ll;
    } else {
      r=rr;
    }
  }
  printf("%.9f\n",1-winPetr((l+r)/2,p,q));
}

int main(void){
  run();
  return 0;
}
