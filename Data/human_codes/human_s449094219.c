#include <stdio.h>
int xxx[10][900][101];
int pattern(int n,int s,int max){
	if(n>1){
		int i,x=0;
		if(xxx[n][s][max]>-1)x=xxx[n][s][max];
		else{
			for(i=max;i>=0;i--){x+=pattern(n-1,s-i,i-1);}
			xxx[n][s][max]=x;
		}
		return x;
	}
	else{
		if(0<=s && s<=max)return 1; else return 0;
	}
}
 
int main(void){
    int n,s,i,j,k;
	for(i=0;i<10;i++){for(j=0;j<900;j++){for(k=0;k<101;k++){xxx[i][j][k]=-1;}}}
    while(scanf("%d %d",&n,&s)*(n+s)){
        printf("%d\n",pattern(n,s,100));
    }
    return 0;
}