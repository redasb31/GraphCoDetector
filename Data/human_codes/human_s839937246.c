#include <stdio.h>
#include <stdlib.h>
//#define ll long long int
#define ll double

typedef struct tag_pair{
	int Pos;
	int Cost;
}Pair;	

Pair nP(int p,int c){Pair P;P.Pos=p;P.Cost=c;return P;}

int cmp(const void *a,const void *b);
int cmp0(const void *a,const void *b);
int WF[102][102];

Pair E[102][102];
int Ec[102];
int From[6000],To[6000],Cost[6000];

ll dp[102];
ll dp2[102];


int Min(int x,int y){return x>y?y:x;}

int main(){
	int N,M,P;
	int i,j,k;
	int c;
	int now;
	while(1){
		scanf("%d %d %d\n",&N,&M,&P);
		if(N==0&&M==0&&P==0)break;
		int Inf=(int)1e9;
		for(i=0;i<N;i++)for(j=0;j<N;j++)WF[i][j]=(i==j)?0:Inf;
		
		for(i=0;i<M;i++){
			scanf("%d %d %d\n",&From[i],&To[i],&Cost[i]);
			WF[From[i]][To[i]]=WF[To[i]][From[i]]=Cost[i];
		}
		
		for(k=0;k<N;k++){
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					WF[i][j]=WF[j][i]=Min(WF[i][j],WF[i][k]+WF[k][j]);
				}
			}
		}
		
		//0->N-1????????????????????????edge????????????
		for(i=0;i<N;i++)Ec[i]=0;
		for(i=0;i<M;i++){
			if(WF[From[i]][N-1]==WF[To[i]][N-1]+Cost[i] && WF[From[i]][0]+Cost[i]==WF[To[i]][0] ){
				E[From[i]][Ec[From[i]]]=nP(To[i],Cost[i]);
				Ec[From[i]]++;
			}
			if(WF[To[i]][N-1]==WF[From[i]][N-1]+Cost[i] && WF[To[i]][0]+Cost[i]==WF[From[i]][0] ){
				E[To[i]][Ec[To[i]]]=nP(From[i],Cost[i]);
				Ec[To[i]]++;
			}
		}
		
		Pair tmp[N];
		for(i=0;i<N;i++){
			tmp[i]=nP(i,WF[i][0]);//???->N-1??????????????¢
		}
		qsort(tmp,N,sizeof(Pair),cmp0);
		
		for(i=0;i<N;i++)dp[i]=0;
		dp[0]=1;
		for(i=0;i<N;i++){
			now=tmp[i].Pos;
			for(j=0;j<Ec[now];j++){
				dp[E[now][j].Pos]+=dp[now];
			}
		}
		
		for(;P>0;P--){
			scanf("%d",&c);
			for(i=0;i<N;i++)dp2[i]=0;//dp2[i]:c??????i???????????????????????°
			dp2[c]=1;
			for(i=0;i<N;i++){
				now=tmp[i].Pos;
				for(j=0;j<Ec[now];j++){
					dp2[E[now][j].Pos]+=dp2[now];
				}
			}
			double prob=(double)dp[c];
			prob/=(double)dp[N-1];
			prob*=(double)dp2[N-1];
			printf("%.12f\n",prob);
		}
		puts("");
	}
	return 0;
}


int cmp(const void *x,const void *y){//???????????????
	Pair X=*(Pair *)x;
	Pair Y=*(Pair *)y;
	
	return X.Cost>Y.Cost?-1:X.Cost<Y.Cost?1:0;
}
int cmp0(const void *x,const void *y){//????????????
	Pair X=*(Pair *)x;
	Pair Y=*(Pair *)y;
	
	return X.Cost>Y.Cost?1:X.Cost<Y.Cost?-1:0;
}