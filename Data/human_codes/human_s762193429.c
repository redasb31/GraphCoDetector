#include <stdio.h>

int main(void){
	char w[101]="";
	int alpha[26]={0};
	scanf("%s",w);
	int i;
	i=0;
	while(w[i] != '\0'){
		alpha[w[i]-97]++;
		i++;
	}
	for(i=0;i<26;i++){
		if(alpha[i] % 2 == 0){
			continue;
		}else{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}