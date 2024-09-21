#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max(a,b) a<b?b:a
#define min(a,b) a<b?b:a

typedef struct POINT{
	double x,y;
}POINT;
typedef struct LINE{
	double x,y;
}LINE;

//double 

double dot(POINT a,POINT b){//内積
	return a.x*b.x + a.y*b.y;
}
double cross(POINT a,POINT b){//外積
	return a.x*b.y - a.y*b.x;
}
POINT make_vec(POINT a,POINT b){//a->b
	b.x -= a.x;
	b.y -= a.y;
	return b;
}

int inclusion(POINT a[],int n,POINT p){
	int ans = 0;
	int i;
	POINT g[n+1];
	double w,rad = 0.0;

	for(i = 0;i < n;i++){
		g[i] = a[i];
	}
	g[n] = g[0];

	for(i = 0;i < n;i++){
		if(g[i].x == p.x && g[i].y == p.y){
			return ans = 1;
		}
	}
	for(i = 0;i < n;i++){
		w = atan2(cross(make_vec(p,g[i]),make_vec(p,g[i+1])),
				dot(make_vec(p,g[i]),make_vec(p,g[i+1])));
		rad += w;
		if(fabs(w - 3.1415926535) <= 0.000001 ||
			 fabs(w + 3.1415926535) <= 0.000001)
			return ans = 1;
	}
	if(fabs(rad - 3.1415926535*2)<=0.000001){//2π
		return ans = 2;//in!
	}
	return ans;
}

int main(){
	int i,m,n;
	POINT g[100];//n
	POINT q;//m
	int ans = 0;

	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d%d",&g[i].x,&g[i].y);
	}
	scanf("%d",&m);
	for(i = 0;i < m;i++){
		scanf("%d%d",&q.x,&q.y);
		ans = inclusion(g,n,q);
		printf("%d\n",ans);
	}
	return 0;
}