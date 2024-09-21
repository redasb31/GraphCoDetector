#include<stdio.h>
int max,len,sum,ans;
int dfs(int depth,int rem,int j){
	int i,a=0;
	if(rem==0&&depth==len){
		return 1;
	}
	if(rem<0||depth>len){
		return 0;
	}
	for(i=j+1;i<=max;i++){
		a+=dfs(depth+1,rem-i,i);
	}
	return a;
}
int main(void){
	int p;
	while(1){
		ans=0;
		scanf("%d %d %d",&max,&len,&sum);
		if(max==0&&len==0&&sum==0){
			break;
		}
		else{
			for(p=1;p<=max;p++){
				ans+=dfs(1,sum-p,p);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}