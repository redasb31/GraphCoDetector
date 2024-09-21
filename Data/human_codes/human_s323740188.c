#include<stdio.h>
#include<math.h>

//http://www.ipsj.or.jp/07editj/promenade/4309.pdf
typedef struct { double x, y, z; } pos;
int n;
pos point[64];

double distance(pos a,pos b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

double solve_by_movement(void){
  int k,i,t;
  pos p;
  double move,max;
  p.x=500.0;
  p.y=500.0;
  p.z=0.0;
  move=0.5;
  while(move>1.0e-8){
    for(t=0;t<100;t++){
    max=0.0;
    for(i=0;i<n;i++)
      if(distance(p,point[i])>max){
        max=distance(p, point[i]);
        k=i;
      }
      p.x+=(point[k].x-p.x)*move;
      p.y+=(point[k].y-p.y)*move;
      p.z+=(point[k].z-p.z)*move;
    }
    move=move/2.0;
  }
  return (max);
}

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lf%lf",&point[i].x,&point[i].y);
    point[i].z=0.0;
  }
  printf("%.12lf\n",solve_by_movement());
}
