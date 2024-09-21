#include <stdio.h>

int main(void){
	
	char a[25],b[25]={'0'};
	int s,t;
	
	scanf("%s",a);
	
	for(s=0;a[s]!='\0';s++){
	}
	
	for(t=0;a[t]!='\0';t++){
		
		b[s-t-1]=a[t];
		
	}
	
	printf("%s",b);
	
	return 0;
}