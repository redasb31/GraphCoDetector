#include <stdio.h>
int main(){
	int n,s,f;
	int flag=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&s,&f);
		while(s!=f){
			if(s<f) printf("%d ",s),s++;
			else printf("%d ",s),s--;
			if(s>9) s=5;
			if(!s) flag=0;
		}
		printf("%d\n",s);
	}
	return 0;
}