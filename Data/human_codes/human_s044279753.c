char*p,tree[99];
leaf[11];
eval(int*ans){
	memset(ans,0,sizeof(int)*16);
	if(*p=='('){
		int l[16],r[16],i,j;
		p++;
		eval(l);
		p++;
		eval(r);
		p++;
		for(i=0;i<16;i++){
			for(j=0;j<16;j++){
				ans[i&j]+=l[i]*r[j];
				ans[i|j]+=l[i]*r[j];
				ans[i^j]+=l[i]*r[j];
			}
		}
	}else{
		ans[leaf[*p-'0']]=1;
		p++;
	}
}
main(){
	int N,i,ans[16];
	for(;scanf("%[^\n]",tree),*tree!='E';){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			int a,b,c,d;
			scanf("%d%d%d%d\n",&a,&b,&c,&d);
			leaf[i]=a+b*2+c*4+d*8;
		}
		p=tree;
		eval(ans);
		printf("%d\n",ans[15]);
	}
	exit(0);
}