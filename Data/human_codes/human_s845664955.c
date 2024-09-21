int dist[100][100],freezer[100],I=1<<29,N,M,L,K,A,H,i,j,k,l;
W(){for(k=0;k<N;k++)for(i=0;i<N;i++)for(j=0;j<N;j++)if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];}
int main(){for(;scanf("%d%d%d%d%d%d",&N,&M,&L,&K,&A,&H),N;){
	memset(dist,0,sizeof(dist));
	memset(freezer,0,sizeof(freezer));
	for(i=0;i<N;i++)for(j=i+1;j<N;j++)dist[i][j]=dist[j][i]=I;
	freezer[A]=freezer[H]=1;
	for(i=0;i<L;i++)scanf("%d",&j),freezer[j]=1;
	for(i=0;i<K;i++)scanf("%d%d%d",&j,&k,&l),dist[j][k]=dist[k][j]=l;
	W();
	for(i=0;i<N;i++)for(j=0;j<N;j++)if(!freezer[i]||!freezer[j]||dist[i][j]>M)dist[i][j]=I;
	W();
	printf((l=dist[A][H])==I?"Help!\n":"%d\n",2*l-(l<M?l:M));
}exit(0);}