char W[9],V[9];Z[2*4],S,N,T,P,M;main(){
	int i,j,k,l,r,d;
	for(;scanf("%d%d%d%s%s%d%d",&S,&N,&T,W,V,&P,&M),S;printf("%.10f\n",1-pow(1-1.0/P,N*r))){
		memset(Z,0,sizeof(Z));
		l=*W=='A'?2:1;
		d=24*60*(*W=='A'?1:7);
		if(*V=='A')for(i=0;i<l;i++)for(j=0;j<4;j++)Z[i*4+j]=1;
		if(*V=='D')for(i=0;i<l;i++)for(j=0;j<2;j++)Z[(i*4+1)+j]=1;
		if(*V=='N')for(i=0;i<l;i++)for(j=0;j<1;j++)Z[i*4+j]=Z[(i*4+3)+j]=1;
		for(r=j=0;j<24*60;r=r>l?r:l,j++)for(k=j,l=i=0;i<M;i++){
			if(k<24*60)l+=Z[(k+S)%(2*24*60)/60/6]&Z[k/60/6];
			k=(k+T)%d;
		}
}exit(0);}