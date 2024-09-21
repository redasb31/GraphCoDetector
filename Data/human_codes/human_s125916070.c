#define _[2<<17]
n,i;A _,B _,T _,F _;long M,D _,P _,R _;
s(u,i,p){i?s(u,T[i],p),B[i]-p?s(B[i],F[B[i]],u),D[u]=D[u]*-~D[B[i]]%M:0,R[i]=R[T[i]]*(B[i]-p?-~D[B[i]]%M:1):(D[u]=1);}
S(u,x,p,i,I){for(i=F[u];I=B[i];I-p?S(I,R[i]*x%M+1,u,0,0),x=x*-~D[I]%M:0)i=T[i];P[u]=x%M;}
//s(u,p,i,I){D[u]=1;for(i=F[u];I=B[i];i=T[i])I-p?s(I,u),D[u]=D[u]*-~D[I]%M:0;}
//S(u,x,p,i,I){for(m(i=F[u],p);I=B[i];I-p?S(I,R[i]*x%M+1,u,0,0),x=x*-~D[I]%M:0)i=T[i];P[u]=x%M;}
//m(i,p){i&&m(T[i],p);R[i]=R[T[i]]*(B[i]-p?printf("p: %d\n",p),-~D[B[i]]:1)%M;}
main(u,v){for(;~scanf("%d%d",&u,&v);)i++?A[i-1]=B[i]=u,B[i-1]=A[i]=v,i++:(n=u,M=v);for(;--i;F[A[i]]=i)T[i]=F[A[i]];
	s(*R=1,F[1],0);
	//s(*R=1,0,0,0,0);
	for(S(1,1,0);i++<n;)printf("%d ",P[i]);
}
