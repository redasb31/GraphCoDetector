#include <stdio.h>
#include <stdlib.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int x,y;
char s[100010];
int main(){
	int n;
	scanf("%d %s",&n,s);
	rep(i,0,n){
		if('A'<=s[i]&&s[i]<='M')x++;
		if('N'<=s[i]&&s[i]<='Z')x--;
		if('a'<=s[i]&&s[i]<='m')y++;
		if('n'<=s[i]&&s[i]<='z')y--;
	}
	printf("%d\n",abs(x)+abs(y));
	rep(i,0,x)putchar('A');
	rep(i,0,-x)putchar('N');
	rep(i,0,y)putchar('a');
	rep(i,0,-y)putchar('n');
	puts("");
}
