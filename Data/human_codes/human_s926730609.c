#include <stdio.h>

int main(void)
{
	char str[3][4];
	int i, f;
	
	while (scanf("%s", str[0]), str[0][0] != '0'){
		scanf("%s", str[1]);
		scanf("%s", str[2]);
		
		f = 0;
		
		for (i = 0; i < 3; i++){
			if (str[i][0] != '+' && str[i][0] == str[i][1] && str[i][0] == str[i][2]){
				printf("%c\n", str[i][0]);
				f = 1;
				break;
			}
			else if (str[0][i] != '+' && str[0][i] == str[1][i] && str[1][i] == str[2][i]){
				printf("%c\n", str[0][i]);
				f = 1;
				break;
			}
			else if ((str[0][0] && str[1][1] && str[1][1] == str[2][2]) || (str[0][2] == str[1][1] && str[1][1] == str[2][0])){
				printf("%c\n", str[1][1]);
				f = 1;
				break;
			}
		}
		
		if (!f){
			printf("NA\n");
		}
	}
	
	return (0);
}