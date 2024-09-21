#include<stdio.h>
#include<math.h>
int cpcc(int p0[2],int r0,int p1[2],int r1,double s[2],double t[2]){
  int x1=p1[0]-p0[0],y1=p1[1]-p0[1],sx=y1,sy=-x1;
  long long a=x1*x1+y1*y1,b=r0*r0-r1*r1+a;
  double c=sqrt(a),d=b/(2*c),e=sqrt(r0*r0-b*b/(4*a));  
  if(a>(r0+r1)*(r0+r1))return 0;
  s[0]=p0[0]+(x1*d+sx*e)/c;
  s[1]=p0[1]+(y1*d+sy*e)/c;
  t[0]=p0[0]+(x1*d-sx*e)/c;
  t[1]=p0[1]+(y1*d-sy*e)/c;
  return 1;
}
int main(){
  int p0[2],p1[2],r0,r1,j;
  double a[2][2],e=0.0000005;
  scanf("%d %d %d %d %d %d",&p0[0],&p0[1],&r0,&p1[0],&p1[1],&r1);
  cpcc(p0,r0,p1,r1,a[0],a[1]);
  if(fabs(a[0][0]-a[1][0])<e)j=a[0][1]+e<a[1][1]?0:1;
  else                       j=a[0][0]+e<a[1][0]?0:1;
  printf("%.9f %.9f %.9f %.9f\n",a[j][0],a[j][1],a[1-j][0],a[1-j][1]);
  return 0;
}