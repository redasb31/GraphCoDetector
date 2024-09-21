#include <stdio.h>

int main(void) {
	char input[1000];
	char v[3];
	char n[3];
	char* ptr;
	int i;
	int ok;
	while(1) {
		scanf("%s",input);
		if(input[0]=='#' && input[1]==0)break;
		for(ptr=input,ok=0;*ptr && !ok;) {
			ptr++;
			for(i=0;i<3;i++) {
				if(*ptr!='~') {
					v[i]=*ptr;
					n[i]=0;
				} else {
					v[i]=*(++ptr);
					n[i]=1;
				}
				ptr+=2;
			}
			if(*ptr)ptr++;
			ok=1;
			if(v[0]==v[1] && n[0]!=n[1])ok=0;
			if(v[1]==v[2] && n[1]!=n[2])ok=0;
			if(v[2]==v[0] && n[2]!=n[0])ok=0;
		}
		puts(ok?"yes":"no");
	}
	return 0;
}