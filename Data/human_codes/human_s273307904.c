#include<stdio.h>
#include<stdlib.h>
#define MAXN 15
n,N,i[MAXN],d[MAXN],w[MAXN],W[1<<MAXN],DP[MAXN][1<<MAXN];
K,k,k0,p;
long long DT[MAXN][1<<MAXN],t,t0,t1,tmin;
P(k,K){
	if(K){
		K-=1<<k;
		P(DP[k][K],K);
		K+=1<<k;
		printf("%d%c",i[k],K==N-1?'\n':' ');
	}
}
main(){
	scanf("%d",&n);
	N=1<<n;
	for(k=0;k<n;k++)
		scanf("%d%d%d",i+k,d+k,w+k);
	for(K=0;K<N;K++){
		W[K]=70;
		for(k=0;k<n;k++){
			if(K&(1<<k))
				W[K]+=w[k]*20;
		}
	}
	for(K=1;K<N-1;K++){
		for(k=0;k<n;k++){
			if(!(K&(1<<k))){
				tmin=1e9;
				for(k0=0;k0<n;k0++){
					if(K&(1<<k0)){
						t0=DT[k0][K-(1<<k0)];
						t1=(long long)abs(d[k0]-d[k])*W[K];
						t=t1+t0;
						if(t<tmin){
							tmin=t;
							p=k0;
						}
					}
				}
				DT[k][K]=tmin;
				DP[k][K]=p;
			}
		}
	}
	tmin=1e9;
	for(k=0;k<n;k++){
		t=DT[k][N-1-(1<<k)];
		if(t<tmin){
			tmin=t;
			k0=k;
		}
	}
	P(k0,N-1);
	return 0;
}