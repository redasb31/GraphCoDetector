#include <stdio.h>
#include <string.h>

int main(void){
	char s[105];
	scanf("%[^\n]", s);
#ifdef DEBUG
printf("%d\n", strlen(s));
#endif
	int min = 114514;
	for(char a = 'a'; a <= 'z'; a++){
		int count = 0;
		int max = 0;
		for(int i = strlen(s)-1; i >= 0; i--){
			if(s[i] == a){
				if(max < count){
					max = count;
				}
				count = 0;
			}
			else count++;
		}
		if(max < count){
			max = count;
		}
		if(min > max){
			min = max;
		}
	}
	printf("%d\n", min);
	return 0;
}