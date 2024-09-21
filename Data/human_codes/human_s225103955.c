#include<stdio.h>
#include<stdlib.h>
#define ll long long
//suffix arrayのO(NlogN)構築
int*makeSA(char*s,int len){
	len++;
	int*SAidx=calloc(len,sizeof(int));
	int*ord=calloc(len,sizeof(int));
	//1文字目
	int cnt1[256]={},cnt2[256]={};
	for(int i=0;i<len;i++)cnt1[s[i]+1]++,cnt2[s[i]+1]|=1;
	for(int i=1;i<256;i++)cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
	for(int i=0;i<len;i++)SAidx[cnt1[s[i]]++]=i,ord[i]=cnt2[s[i]];
	
	int*cnt=calloc(len+1,sizeof(int));
	int*idx2=calloc(len,sizeof(int));
	int*temp=calloc(len,sizeof(int));
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

char s[100010];
ll cnt[100010];
ll wei[100010];
int main(){
	ll n,k;
	scanf("%lld%lld %s",&n,&k,s);
	k--;
	ll crr=0;
	for(int i=0;i<n;i++){
		cnt[n-i]+=cnt[n-i+1];
		if(s[i]=='0'){
			cnt[0]+=crr+1;
			crr++;
		}else{
			cnt[n-i]+=crr+1;
			wei[i]=crr+1;
			crr=0;
		}
	}
	
	int keta=0;
	while(k>=cnt[keta])k-=cnt[keta++];
	if(keta==0){
		puts("0");
		return 0;
	}
	//keta桁で、小さい方からk番目
	int*p=makeSA(s,n);

	for(int i=0;i<n;i++){
		if(p[i]+keta<=n){
			k-=wei[p[i]];
			if(k<0){
				for(int j=0;j<keta;j++)putchar(s[p[i]+j]);puts("");
				return 0;
			}
		}
	}
}
