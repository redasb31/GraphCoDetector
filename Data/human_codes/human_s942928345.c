#include<stdio.h>
#include<stdlib.h>
#define inf 999999999999999999

long long min(long long x,long long y){if(x<y){return x;}return y;}

long long max(long long x,long long y){if(x>y){return x;}return y;}

typedef struct{
	long long num;
	long long pair;
}data;

int sortfnc(const void *a,const void *b){
    if(((data*)a)->num == ((data*)b)->num){return 0;}
    if(((data*)a)->num < ((data*)b)->num){return -1;}
    return 1;
}

int main(void){
	long long af[262144]={0},bf[262144]={0},amin = inf,amax = 0,bmin = inf,bmax = 0;
	long long mindis = inf;
	long long n,x,y,i,res=inf;
	data bd[524288];
	scanf("%lld",&n);
	for(i = 0;i < n;i++){
		scanf("%lld%lld",&x,&y);
		bd[2*i+0].num = x;
		bd[2*i+1].num = y;
		bd[2*i+0].pair = i;
		bd[2*i+1].pair = i;
	}
	qsort(bd,2*n,sizeof(data),sortfnc);
	i = 0;
	while(1){
		if(af[bd[i].pair]){break;}
		amin = min(bd[i].num,amin);
		af[bd[i].pair] = 1;
		i++;
	}
	bmin = bd[i].num;
	i = 2*n-1;
	while(1){
		if(bf[bd[i].pair]){break;}
		bmax = max(bd[i].num,bmax);
		bf[bd[i].pair] = 1;
		i--;
	}
	amax = bd[i].num;
	printf("%lld\n",min((max(amax,bmin)-min(amax,bmin))*(bmax-amin),(amax-amin)*(bmax-bmin)));
	return 0;
}