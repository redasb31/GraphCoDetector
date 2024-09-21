#include <stdio.h>
#include <string.h>
int main(void){
	int i,n,f;
	char s[101],stk[101];
	while(1){
		fgets(s,101,stdin);
		if(*s=='.'){
			break;
		}
		s[strlen(s)]='\0';
		memset(stk,0,sizeof(stk));
		n=0;
		f=1;
		for(i=0;s[i];i++){
			if(s[i]=='('||s[i]=='['){
				stk[n++]=s[i];
			}
			else if(s[i]==')'){
				if(!n||stk[n-1]!='('){
					f=0;
				}
				else{
					n--;
				}
			}
			else if(s[i]==']'){
				if(!n||stk[n-1]!='['){
					f=0;
				}
				else{
					n--;
				}
			}
		}
		if(f&&!n){
			puts("yes");
		}
		else{
			puts("no");
		}
	}
	return 0;
}