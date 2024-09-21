#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j,k;
	char s[10],s1[]="A",s2[]="Un",c1[100],c2[100],c3[100];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s",s);
		if(strcmp(s,s1)==0){
			c1[i]='1';
			c2[i]='0';
		}
		else if(strcmp(s,s2)==0){
			c1[i]='0';
			c2[i]='1';
		}
	}
	c1[i]='\0';
	c2[i]='\0';
	
	for(i=0;c2[i]!='1';i++);
	for(j=i;j<strlen(c2);j++)c3[j-i]=c2[j];
	for(k=0;k<i;k++)c3[k+j-i]='0';
	
	if(strcmp(c1,c3)==0)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}