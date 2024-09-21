#include<stdio.h>
#include<string.h>
#include<math.h>
int main (){
	char str[11];
	long long int a=0,b,i,c=0,f;
	scanf("%s",str);
	b=strlen(str);
	for(i=0;i<b;i++){
		a=a+(str[i]-'0');
		f=pow(10,b-i-1)
		c=c+((str[i]-'0')*f);	
	}
	if(c%b==0){
		printf("Yes\n");
		}
	else printf("No\n");
	return 0;
}
