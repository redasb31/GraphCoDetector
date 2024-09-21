int w,h;
int d[9][9];
int a[4]={-1,0,1,0};
int X,Y,C,t;

int b=0;
int dfs(int x,int y,int c){
	if(b++ > (1<<25))return 2;
	int i=0;
	if(!c&&x==X&&y==Y)return 1;
	if(d[y][x])return 0;
	 d[y][x]=1;
	for(;i<4;i++)if(t=dfs(x+a[i],y+a[(i+1)%4],c-1))return t;
	return d[y][x]=0;
}
int main(i,j){
	for(;C=0,scanf("%d%d\n",&w,&h),h;puts(C>3&&dfs(X,Y,C)==1?"Yes":"No")){
		memset(d,-1,324);
		for(j=1;j<=h;j++)for(i=1;i<=w;i++)scanf("%d",&t),(d[j][i]=t)||(++C,X=i,Y=j);
	}
}