#include<stdio.h>
int main(){
	int tmp,ary[5],i,j;
	for(i=0;i<5;i++){
		scanf("%d",&ary[i]);
	}
	for(j=0;j<4;j++){
		for(i=3;i>=j;i--){
			if(ary[i]<ary[i+1]){
				tmp=ary[i+1];
				ary[i+1]=ary[i];
				ary[i]=tmp;
			}
		}
	}
	for(i=0;i<5;i++){	
		printf("%d ",ary[i]);
	}
	return 0;
}