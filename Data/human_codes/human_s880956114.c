main(a,b,c,X,Y,A,f,i,j){for(;scanf("%d%d%d",&a,&b,&c),a;printf("%d %d\n",X,Y))
for(A=2147483647,f=i=0;!f;i++)
	for(j=0;j<=i;j++)
		if(a*j+b*(i-j)==c||a*j==b*(i-j)+c||a*j+c==b*(i-j))
			if(f=1,A>a*j+b*(i-j))A=a*j+b*(i-j),X=j,Y=i-j;
exit(0);}