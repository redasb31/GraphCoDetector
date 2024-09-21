#include<stdio.h>
int main(){
	char ch[1001];
	int i = 0,count,count2=0;
	scanf("%s",ch);
	while(ch[i]!='\0'){
		i++; 
	}
	for(int x = 0;x < i;x++){
		count = 0;
		if(ch[x] != '\0'){
			for(int y = i-1;y >=x;y--){
				if(ch[x] == ch[y]){
					ch[y] = '\0';
					count++;
				}
			}
		}
		if((count % 2) == 1){
			count2++;
		}
	}
	if((count2 % 2) == 1){
		printf("%d\n",(count2/2)+1);
	}
	else{
		printf("%d\n",count2/2);
	}
	return 0;
}