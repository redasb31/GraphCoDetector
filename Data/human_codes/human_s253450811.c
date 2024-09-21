#include<stdio.h>
#include<stdlib.h>

int main(void){
	char s[131072];
	int g=0,p=0,i,n;
	scanf("%s",s);
	n=strlen(s);
	for(i=1;i<=n;i++){
		if(s[i] == 'g'){g++;}
		if(s[i] == 'p'){p++;}
	}
	printf("%d\n",(n/2)-p);
	return 0;
}