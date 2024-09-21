#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))


//セグ木ここから
//*
//↓ここを変える
typedef struct atai{ll a,s;}atai;
atai xx(atai x,atai y){
	atai r;
	if(x.a<y.a)r=y;
	else if(x.a>y.a)r=x;
	else{
		r.a=x.a;
		r.s=max(x.s,y.s);
	}
	return r;
}
atai aid={0};
//↑ここを変える

int segNUM;
atai *segN,*seg;
void seguse(int n){
	segN=(atai*)calloc(2*n,sizeof(atai));
	segNUM=n;
	seg=segN+segNUM;
	rep(i,1,2*segNUM)segN[i]=aid;
}
//seg[]に値を与えてから初期化
void seginit(){for(int node=segNUM-1;node;node--)segN[node]=xx(segN[node*2],segN[node*2+1]);}
void segupdate(int node,atai x){
	//seg[node]をxに更新
	node+=segNUM;
	segN[node]=x;
	while(node/=2)segN[node]=xx(segN[node*2],segN[node*2+1]);
}

atai segcalcsub(int l,int r,int k,int cl,int cr){
	if(l>=r)return aid;
	//完全に含むとき
	if(l<=cl&&cr<=r)return segN[k];

	int cm=(cl+cr)/2;
	//左側だけ
	if(r<=cm)return segcalcsub(l,r,2*k  ,cl,cm);
	//右側だけ
	if(cm<=l)return segcalcsub(l,r,2*k+1,cm,cr);
	//両方
	return xx(segcalcsub(l,r,2*k,cl,cm),segcalcsub(l,r,2*k+1,cm,cr));
}
atai segcalc(int l,int r){return segcalcsub(l,r,1,0,segNUM);}
//セグ木ここまで
//*/

ll a[100010];
int idx[100010];
int c(const void*p,const void*q){
	if(a[*(int*)p]<a[*(int*)q])return -1;
	if(a[*(int*)p]>a[*(int*)q])return 1;
	if(*(int*)p>*(int*)q)return -1;
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%lld",a+i);
		idx[i]=i;
	}
	qsort(idx,n,sizeof(int),c);
	seguse(1<<17);
	rep(i,0,n){
		atai x=segcalc(0,idx[i]);
		x.a++;
		x.s+=a[idx[i]];
		segupdate(idx[i],x);
	}
	printf("%lld\n",segcalc(0,n).s);
}
