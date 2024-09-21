#include<stdio.h>

int l[1000010];

int main(){
	int s;
	scanf("%d",&s);
	
	for(int i=1;;i++){
		if(l[s]==1){
			printf("%d\n",i);
			return 0;
		}
		l[s]=1;
		if(s%2==0)s/=2;
		else s=s*3+1;
	}
	return 0;
}