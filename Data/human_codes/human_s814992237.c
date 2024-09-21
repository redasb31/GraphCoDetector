#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASC_ORDER		(1)
#define DES_ORDER		(0)

#define MAX_ARRAY_NUM	(9)

void sort(char *array, int op);
void swap(char *a, char *b);
int my_atoi(char *val);

int main(void)
{
	int n;
	char input[MAX_ARRAY_NUM], min[MAX_ARRAY_NUM], max[MAX_ARRAY_NUM];
	
	scanf("%d", &n);
	
	while (n--){
		scanf("%s", input);
		
		memcpy(min, input, sizeof(input));
		memcpy(max, input, sizeof(input));
		
		sort(min, ASC_ORDER);
		sort(max, DES_ORDER);
		
		printf("%d\n", my_atoi(max) - my_atoi(min));
	}
	
	return (0);
}

void sort(char *array, int op)
{
	int i, j;
	
	swap((array + 0), (array + 1));
	
	for (i = 0; i < MAX_ARRAY_NUM - 1; i++){
		for (j = MAX_ARRAY_NUM - 2; j > 0; j--){
			
			switch (op){
				case ASC_ORDER:
					if (*(array + j) < *(array + j - 1)){
						swap((array + j), (array + j - 1));
					}
					break;
				
				case DES_ORDER:
					if (*(array + j) > *(array + j - 1)){
						swap((array + j), (array + j - 1));
					}
					break;
				
				default:
					//do nothing
					break;
			}
			
		}
	}
}

void swap(char *a, char *b)
{
	char tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;

}

int my_atoi(char *val)
{
	int ret;
	int digit;
	int i;
	
	ret = 0;
	for (i = MAX_ARRAY_NUM - 2, digit = 1; i >= 0; i--, digit *= 10){
		ret += (*(val + i) - '0') * digit;
	}
	
	return (ret);
}
