#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)


//suffix arrayのO(NlogN)構築
//p[i]=辞書順i番目のsuffixは何文字目から始まるものか
//*
int*makeSA(char*s,int len){
	len++;
	int*SAidx=(int*)calloc(len,sizeof(int));
	int*ord=(int*)calloc(len,sizeof(int));
	//1文字目
	int cnt1[256]={},cnt2[256]={};
	for(int i=0;i<len;i++)cnt1[s[i]+1]++,cnt2[s[i]+1]|=1;
	for(int i=1;i<256;i++)cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
	for(int i=0;i<len;i++)SAidx[cnt1[s[i]]++]=i,ord[i]=cnt2[s[i]];
	
	int*cnt=(int*)calloc(len+1,sizeof(int));
	int*idx2=(int*)calloc(len,sizeof(int));
	int*temp=(int*)calloc(len,sizeof(int));
	for(int k=1;k<len;k*=2){
		//2*k文字まで見る
		for(int i=0;i<len;i++)cnt[i]=0;
		for(int i=0;i<len;i++)cnt[ord[i]+1]++;
		for(int i=1;i<len;i++)cnt[i]+=cnt[i-1];
		for(int i=0;i<len;i++)idx2[cnt[ord[(SAidx[i]-k+len)%len]]++]=(SAidx[i]-k+len)%len;
		temp[idx2[0]]=0;
		for(int i=1;i<len;i++)temp[idx2[i]]=temp[idx2[i-1]]+(ord[idx2[i-1]]!=ord[idx2[i]]||ord[(idx2[i-1]+k)%len]!=ord[(idx2[i]+k)%len]);
		for(int i=0;i<len;i++)ord[i]=temp[i],SAidx[i]=idx2[i];
	}
	free(temp);
	free(idx2);
	free(cnt);
	free(ord);
	return SAidx+1;
}
//*/

//SAを使ってlongest common prefix arrayをO(N)構築
//p[i]=s[SA[i-1]:n]とs[SA[i]:n]のLCP
//*
int*makeLCPA(char*s,int len,int*SA){
	int*SAr=(int*)calloc(len,sizeof(int));
	int*LCPA=(int*)calloc(len,sizeof(int));
	for(int i=0;i<len;i++)SAr[SA[i]]=i;
	int cnt=0;
	for(int i=0;i<len;i++){
		if(SAr[i])while(s[SA[SAr[i]-1]+cnt]==s[i+cnt])cnt++;
		else cnt=0;
		LCPA[SAr[i]]=cnt;
		if(cnt)cnt--;
	}
	free(SAr);
	return LCPA;
}
//*/


char s[500010];

int main(){
	scanf("%s",s);
	int n=strlen(s);
	int*SA=makeSA(s,n);
	int*LCPA=makeLCPA(s,n,SA);
	ll ans=n*(n+1LL)/2;
	rep(i,1,n)ans-=LCPA[i];
	printf("%lld\n",ans);
}