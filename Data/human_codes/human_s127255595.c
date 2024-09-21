#include<stdio.h>

int main(void){
	int h,w,r = 0,i,j;
	char s[16];
	scanf("%d%d",&h,&w);
	for(i = 0;i < h;i++){
		scanf("%s",s);
		for(j = 0;j < w;j++){
			if(s[j] == '#'){r++;}
		}
	}
	if(h+w-1 == r){printf("Possible\n");}
	else{printf("Impossible\n");}
	return 0;
}