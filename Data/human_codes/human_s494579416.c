#include <stdio.h>
#include <string.h>

char input[600];

int catcheck(int start,int end) {
	int i;
	int kaisou;
	if(start>=end)return 1;
	if(input[start]!='m' || input[end-1]!='w')return 0;
	kaisou=0;
	for(i=start+1;i<end-1;i++) {
		if(kaisou==0 && input[i]=='e')break;
		if(input[i]=='m')kaisou++;
		if(input[i]=='w')kaisou--;
		if(kaisou<0)return 0;
	}
	return catcheck(start+1,i) && catcheck(i+1,end-1);
}

int main(void) {
	scanf("%s",input);
	puts(catcheck(0,strlen(input))?"Cat":"Rabbit");
	return 0;
}