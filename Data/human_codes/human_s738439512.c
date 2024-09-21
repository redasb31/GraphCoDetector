#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

//*
//遅延セグ木ここから
//↓ここを変える
typedef struct sayouso{ll k;}sayouso;
typedef struct atai{ll m,M;ll mc,Mc;}atai;
//↑ここを変える

typedef struct node{sayouso T;atai x;}node;
node *lsegN,*lseg;
ll lsegNUM;

//↓ここから変える
sayouso sid={0};
atai aid={1e18,-1e18,1,1};
atai xx(atai x,atai y){
	atai r;
	if(x.m<y.m){r.m=x.m;r.mc=x.mc;}
	else if(x.m>y.m){r.m=y.m;r.mc=y.mc;}
	else{r.m=y.m;r.mc=x.mc+y.mc;}
	if(x.M>y.M){r.M=x.M;r.Mc=x.Mc;}
	else if(x.M<y.M){r.M=y.M;r.Mc=y.Mc;}
	else{r.M=y.M;r.Mc=x.Mc+y.Mc;}
	return r;
}
atai Tx(sayouso T,atai x){
	atai ret;
	ret.m=x.m+T.k;
	ret.M=x.M+T.k;
	ret.mc=x.mc;
	ret.Mc=x.Mc;
	return ret;
}
sayouso TT(sayouso S,sayouso T){
	sayouso ret;
	ret.k=S.k+T.k;
	return ret;
}
//↑ここまで変える

//要素数(2ベキ)でこれを呼ぶ
void lseguse(ll n){
	lsegN=(node*)calloc(2*n,sizeof(node));
	lsegNUM=n;
	lseg=lsegN+lsegNUM;
	rep(i,0,lsegNUM){
		lseg[i].x=aid;
		lseg[i].T=sid;
	}
	for(int i=lsegNUM-1;i>0;i--){
		lsegN[i].x=xx(lsegN[2*i].x,lsegN[2*i+1].x);
		lsegN[i].T=sid;
	}
}
//lseg[i].xに値を与えてから初期化
void lseginit(){
	for(int i=lsegNUM-1;i>0;i--)lsegN[i].x=xx(lsegN[2*i].x,lsegN[2*i+1].x);
}
void lsegupdatesub(ll l,ll r,sayouso T,ll i,ll cl,ll cr){
	if(l>=r)return;
	//disjointなとき
	if(cr<=l||r<=cl)return;
	//完全に含むとき
	if(l<=cl&&cr<=r){
		lsegN[i].T=TT(T,lsegN[i].T);
		return;
	}
	//どちらでもないとき
	//遅延伝播
	lsegN[2*i  ].T=TT(lsegN[i].T,lsegN[2*i  ].T);
	lsegN[2*i+1].T=TT(lsegN[i].T,lsegN[2*i+1].T);
	//再帰的に更新
	ll cm=(cl+cr)/2;
	lsegupdatesub(l,r,T,2*i  ,cl,cm);
	lsegupdatesub(l,r,T,2*i+1,cm,cr);
	//自身のnodeを更新
	lsegN[i].x=xx(Tx(lsegN[2*i].T,lsegN[2*i].x),Tx(lsegN[2*i+1].T,lsegN[2*i+1].x));
	lsegN[i].T=sid;
}
void lsegupdate(ll l,ll r,sayouso T){lsegupdatesub(l,r,T,1,0,lsegNUM);}
atai lsegcalcsub(ll l,ll r,ll i,ll cl,ll cr){
	if(l>=r)return aid;
	//完全に含むとき
	if(l<=cl&&cr<=r)return Tx(lsegN[i].T,lsegN[i].x);

	ll cm=(cl+cr)/2;
	//遅延伝播(変更はないので配るだけで良い)
	lsegN[2*i  ].T=TT(lsegN[i].T,lsegN[2*i  ].T);
	lsegN[2*i+1].T=TT(lsegN[i].T,lsegN[2*i+1].T);
	lsegN[i].x=Tx(lsegN[i].T,lsegN[i].x);
	lsegN[i].T=sid;

	//左側だけ
	if(r<=cm)return lsegcalcsub(l,r,2*i  ,cl,cm);
	//右側だけ
	if(cm<=l)return lsegcalcsub(l,r,2*i+1,cm,cr);
	//両方
	return xx(lsegcalcsub(l,r,2*i,cl,cm),lsegcalcsub(l,r,2*i+1,cm,cr));
}
atai lsegcalc(ll l,ll r){return lsegcalcsub(l,r,1,0,lsegNUM);}
//遅延セグ木ここまで
//*/


atai calc(atai a,atai b){
	atai ret={1e18,-1e18,0,0};
	ll aa[2]={a.m,a.M},bb[2]={b.m,b.M};
	ll ac[2]={a.mc,a.Mc},bc[2]={b.mc,b.Mc};
	for(int i=a.m==a.M;i<2;i++)for(int j=b.m==b.M;j<2;j++){
		ll temp=aa[i]*bb[j];
		ll cnt=ac[i]*bc[j];
		if(temp==ret.m){
			ret.mc+=cnt;
		}else if(temp<ret.m){
			ret.m=temp;
			ret.mc=cnt;
		}
		if(temp==ret.M){
			ret.Mc+=cnt;
		}else if(temp>ret.M){
			ret.M=temp;
			ret.Mc=cnt;
		}
	}
	return ret;
}

int b[100010];
int q1[100010],q2[100010],q3[100010],q4[100010],q5[100010];
atai a[100010];
int main(){
	int h,w,q;
	scanf("%d%d%d",&h,&w,&q);
	lseguse(1<<17);
	for(int i=1;i<=h;i++){
		int t;
		scanf("%d",&t);
		lseg[i].x.m=lseg[i].x.M=t;
	}
	lseginit();
	for(int i=1;i<=w;i++)scanf("%d",b+i);
	for(int i=0;i<q;i++){
		scanf("%d",q1+i);
		if(q1[i]==1){
			scanf("%d%d%d",q2+i,q3+i,q4+i);
			sayouso T={q4[i]};
			lsegupdate(q2[i],q3[i]+1,T);
		}else if(q1[i]==2){
			scanf("%d%d%d",q2+i,q3+i,q4+i);
		}else{
			scanf("%d%d%d%d",q2+i,q3+i,q4+i,q5+i);
			a[i]=lsegcalc(q2[i],q3[i]+1);
		}
	}
	
	free(lsegN);
	lseguse(1<<17);
	for(int i=1;i<=w;i++)lseg[i].x.m=lseg[i].x.M=b[i];
	lseginit();
	for(int i=0;i<q;i++){
		if(q1[i]==2){
			sayouso T={q4[i]};
			lsegupdate(q2[i],q3[i]+1,T);
		}else if(q1[i]>=3){
			atai bb=lsegcalc(q4[i],q5[i]+1);
			atai ans=calc(a[i],bb);
			if(ans.m==0||ans.M==0){
				int zeroa=a[i].m==0?a[i].mc:a[i].M==0?a[i].Mc:0;
				int zerob=  bb.m==0?  bb.mc:  bb.M==0?  bb.Mc:0;
				ll hh=q3[i]-q2[i]+1;
				ll ww=q5[i]-q4[i]+1;
				ll zeros=hh*ww-(hh-zeroa)*(ww-zerob);
				if(ans.m==0)ans.mc=zeros;
				if(ans.M==0)ans.Mc=zeros;
			}
			if(q1[i]==3)printf("%lld %lld\n",ans.m,ans.mc);
			if(q1[i]==4)printf("%lld %lld\n",ans.M,ans.Mc);
		}
	}
}


