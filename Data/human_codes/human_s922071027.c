#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define zahyoutype double
typedef struct Point{zahyoutype x,y;}P;
typedef struct line{P p1,p2;}L;

P crosspoint(L s,L t){
	zahyoutype x=1;if(x/2==0){puts("type error");exit(0);}
	double deno=(s.p1.x-s.p2.x)*(t.p1.y-t.p2.y)-(t.p1.x-t.p2.x)*(s.p1.y-s.p2.y);
	zahyoutype xnume=  s.p1.x*t.p1.x*(s.p2.y-t.p2.y)-s.p1.x*t.p2.x*(s.p2.y-t.p1.y)-s.p2.x*t.p1.x*(s.p1.y-t.p2.y)+s.p2.x*t.p2.x*(s.p1.y-t.p1.y);
	zahyoutype ynume=-(s.p1.y*t.p1.y*(s.p2.x-t.p2.x)-s.p1.y*t.p2.y*(s.p2.x-t.p1.x)-s.p2.y*t.p1.y*(s.p1.x-t.p2.x)+s.p2.y*t.p2.y*(s.p1.x-t.p1.x));
	P p={xnume/deno,ynume/deno};
	return p;
}
double seglen(L s){return hypot(s.p2.x-s.p1.x,s.p2.y-s.p1.y);}
double distPP(P p,P q){return hypot(p.x-q.x,p.y-q.y);}

void readpoint(P*p){zahyoutype x=1;scanf(x/2?"%lf%lf":"%ld%ld",&p->x,&p->y);}
void printpoint(P p){zahyoutype x=1;printf(x/2?"%.f %.f\n":"%ld %ld\n",p.x,p.y);}

int main(){
	P p1;
	int r1;
	readpoint(&p1);
	scanf("%d",&r1);
	P p2;
	int r2;
	readpoint(&p2);
	scanf("%d",&r2);
	double dist=distPP(p1,p2);
	double theta=acos((r1*r1+dist*dist-r2*r2)/2/r1/dist);
	double arg=atan2(p2.y-p1.y,p2.x-p1.x);
	double x1,y1,x2,y2;
	x1=p1.x+r1*cos(arg+theta);
	y1=p1.y+r1*sin(arg+theta);
	x2=p1.x+r1*cos(arg-theta);
	y2=p1.y+r1*sin(arg-theta);
	if(x2<x1||(x2==x1&&y2<y1)){
		double t=x1;x1=x2;x2=t;
		t=y1;y1=y2;y2=t;
	}
	printf("%.9f %.9f %.9f %.9f\n",x1,y1,x2,y2);
}
