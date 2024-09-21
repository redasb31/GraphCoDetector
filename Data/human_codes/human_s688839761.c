#include <stdio.h>

#define N_MAX 100000
#define A_MAX 100000

int parse(char *text);

int main(void)
{
	int i, n, max, cnt;
	int count[A_MAX+2];
	char buf[7];

	for(i=0;i<A_MAX+1;i++) {
		count[i] = 0;
	}

	scanf("%d%*c", &n);

	i = 0;
	while(1) {
		int flag = 0;
		scanf("%c", &buf[i]);
		if(buf[i] == ' ' || buf[i] == '\n') {
			if(buf[i] == '\n') flag = 1;
			buf[i] = '\0';
			int a = parse(buf);
			count[a]++;
			if(a-1 >= 0) count[a-1]++;
			if(a+1 <= A_MAX+1) count[a+1]++;
			if(flag) break;
			i = 0;
			continue;
		}
		i++;
	}

	max = 0;
	for(i=0;i<A_MAX+1;i++) {
		if(count[i] > max) {
			max = count[i];
		}
	}
	printf("%d\n", max);

	return 0;
}

int parse(char *text)
{
	int i = 0, ret = 0, len;
	while(1) {
		if(text[i] == '\0') {
			len = i;
			break;
		}
		i++;
	}

	for(i=len-1;i>=0;i--) {
		int a = 1, j;
		for(j=0;j<len-i-1;j++) a *= 10;
		ret += (int)(text[i] - '0') * a;
	}

	return ret;
}
