N,E[21][21];
T0(f,c){
	int i,tsum=0;
	for(i=2;i<=N;i++)
		if(i!=f&&E[c][i])
			tsum+=T0(c,i)+2*E[c][i];
	//printf("T0_%d(%d)=%d\n",f,c,tsum);
	return tsum;
}
T1(f,c,l){
	int i,tsum=E[c][l]+T2(c,l);
	for(i=2;i<=N;i++)
		if(i!=f&&i!=l&&E[c][i])
			tsum+=T0(c,i)+2*E[c][i];
	//printf("T1_%d(%d,%d)=%d\n",f,c,l,tsum);
	return tsum;
}
T2(f,c){
	int l,t,tmin=1e9;
	for(l=2;l<=N;l++)
		if(l!=f&&E[c][l]){
			t=T1(f,c,l);
			if(t<tmin)
				tmin=t;
		}
	if(tmin==1e9)
		tmin=0;
	//printf("T2_%d(%d)=%d\n",f,c,tmin);
	return tmin;
}
main(){
	for(;scanf("%d",&N),N;){
		int i,j,bn[21]={0};
		for(i=0;i<N-1;i++){
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			E[a][b]=E[b][a]=t;
			bn[a]++,bn[b]++;
		}
		//´ª1{µ©©©ÁÄ¢È¢ÍNU·éKvª³¢ÌÅÁ·(1Íc·)
		for(i=2;i<=N;i++)
			if(bn[i]==1)
				for(j=1;j<=N;j++)
					E[i][j]=E[j][i]=0;
		printf("%d\n",T2(0,1));
		memset(E,0,sizeof(E));
	}
	exit(0);
}