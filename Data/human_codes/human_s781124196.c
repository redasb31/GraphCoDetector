#include <stdio.h>
#include <stdlib.h>

typedef struct Bomb{
	int map[8][8];
} BOMB;

Input(BOMB *);
void explode(BOMB *);

int x_cnt, y_cnt;

int main()
{
	int input_times, input_cnt;
	BOMB Bomb[50];
	int x, y;
	
	scanf("%d", &input_times);
	for(input_cnt = 0; input_cnt < input_times; input_cnt++){
		Input(&Bomb[input_cnt]);
		scanf("%d\n%d", &x, &y);
		Bomb[input_cnt].map[x - 1][y - 1] = 2;
		explode(&Bomb[input_cnt]);
	}
	
	for(input_cnt = 0; input_cnt < input_times; input_cnt++){
		printf("Data %d:\n", input_cnt + 1);
		for(y_cnt = 0; y_cnt < 8; y_cnt++){
			for(x_cnt = 0; x_cnt < 8; x_cnt++)
				printf("%d", Bomb[input_cnt].map[x_cnt][y_cnt]);
			printf("\n");
		}
	}
	
	return 0;
}

Input(BOMB *bomb)
{
	char dump;
	dump = getchar();
	for(y_cnt = 0; y_cnt < 8; y_cnt++){
		dump = getchar();
		for(x_cnt = 0; x_cnt < 8; x_cnt++)
			bomb->map[x_cnt][y_cnt] = getchar() - 48;
	}
}

void explode(BOMB* bomb_map)
{
	int explode_cnt;
	for(y_cnt = 0; y_cnt < 8; y_cnt++)
		for(x_cnt = 0; x_cnt < 8; x_cnt++)
			/*Find exploded bomb and process*/
			if(bomb_map->map[x_cnt][y_cnt] == 2){
				bomb_map->map[x_cnt][y_cnt] = 0;
				/*Left*/
				explode_cnt = 1;
				while((x_cnt - explode_cnt) >= 0 && explode_cnt <= 3){
				    if((bomb_map->map[x_cnt - explode_cnt][y_cnt]) == 1)
				        (bomb_map->map[x_cnt - explode_cnt][y_cnt]) = 2;
				    explode_cnt++;
				}
				/*Right*/
				explode_cnt = 1;
				while((x_cnt + explode_cnt) <= 7 && explode_cnt <= 3){
				    if((bomb_map->map[x_cnt + explode_cnt][y_cnt]) == 1)
				        (bomb_map->map[x_cnt + explode_cnt][y_cnt]) = 2;
				    explode_cnt++;
				}
				/*Down*/
				explode_cnt = 1;
				while((y_cnt - explode_cnt) >= 0 && explode_cnt <= 3){
				    if((bomb_map->map[x_cnt][y_cnt - explode_cnt]) == 1)
				        (bomb_map->map[x_cnt][y_cnt - explode_cnt]) = 2;
				    explode_cnt++;
				}
				/*Up*/
				explode_cnt = 1;
				while((y_cnt + explode_cnt) <= 7 && explode_cnt <= 3){
				    if((bomb_map->map[x_cnt][y_cnt + explode_cnt]) == 1)
				        (bomb_map->map[x_cnt][y_cnt + explode_cnt]) = 2;
				    explode_cnt++;
				}
				explode(bomb_map);
			}
}