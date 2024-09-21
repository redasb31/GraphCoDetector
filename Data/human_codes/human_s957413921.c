#include<stdio.h>
int main(void) {
	char s1[200], s2[200];
	int i=0,cnt,jud;
	while (1) {
		cnt = 0;
		jud = 0;
		i = 0;
		fgets(s1,sizeof(s1),stdin);
		scanf(s2,sizeof(s2),stdin);
		if (s1[0] == '.') {
			break;
		}
		while (s1[i] != '\n') {
			if ((s1[i] != s2[i]) && (jud == 0)) {
				cnt++;
				jud = 1;
			}
			if (s1[i] == ';') {
				jud = 0;
			}
			i++;
		}
	}
	if (cnt == 0) {
		printf("IDENTICAL\n");
	}
	else if(cnt==1){
		printf("CLOSE\n");
	}else{
		printf("DIFFERENT\n");
	}
	return 0;
}
