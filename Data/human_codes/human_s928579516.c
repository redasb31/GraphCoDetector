#include<stdio.h>

int main(){
	int H,W;
	scanf("%d%d",&H,&W);
	char s[W+1][H];
	for(int i=0;i<H;i++)scanf("%s",s[i]);
	
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		if(s[j][i]=='#'){
			int f1,f2,f3,f4;
			if(i==0)f1=0;
			else if(s[j][i-1]=='.')f1=0;
			else f1=1;
			if(j==W-1)f2=0;
			else if(s[j+1][i]=='.')f2=0;
			else f2=1;
			if(i==H-1)f3=0;
			else if(s[j][i+1]=='.')f3=0;
			else f3=1;
			if(j==0)f4=0;
			else if(s[j-1][i]=='.')f4=0;
			else f4=1;
			
			if(f1+f2+f3+f4==0){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}