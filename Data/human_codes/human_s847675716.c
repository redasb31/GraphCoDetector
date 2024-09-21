#include<stdio.h>

int main(){
	while(1){
		char ch;
		int con=1;
		int cou=0;
		int m,n;
		int i,j;
		int ans=0;
		scanf("%d",&n);
		if(n==0)return 0;
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf(" %c",&ch);
			if(ch=='I'){
				if(con==0){
					cou++;
					if(cou==n+1){
						ans++;
						cou--;
					}
				}
				else cou=1;
				con=1;
			}
			if(ch=='O'){
				if(con==0)cou=0;
				con=0;
			}
		}
		printf("%d\n",ans);
	}
}