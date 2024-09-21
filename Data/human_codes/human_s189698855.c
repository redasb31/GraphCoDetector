#include <stdio.h>

int main(void)
{
	int i, dice[7];
	char order[101];

	for (i = 1; i < 7; i++)
		scanf("%d", &dice[i]);

	scanf("%s", order);

	for (i = 0; order[i] != '\0'; i++){

		dice[0] = dice[1];

		switch (order[i]){

		case 'E':
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = dice[0];
			break;

		case 'N':
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = dice[0];
			break;

		case 'S':
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = dice[0];
			break;

		case 'W':
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = dice[0];
			break;

		}
	}

	printf("%d\n", dice[1]);

	return 0;
}
