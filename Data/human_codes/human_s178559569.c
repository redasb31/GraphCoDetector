#include <stdio.h>

int main()
{
	int input_m, input_n_min, input_n_max;
	int score_P[200];
	int score_gap, max_score_gap = 0;
	int answer_n;
	int counter_i;
	
	for( ; ; )
	{
		scanf("%d %d %d", &input_m, &input_n_min, &input_n_max);
		if(input_m == 0 && input_n_min == 0 && input_n_max == 0)
			break;
		
		for(counter_i = 0 ; counter_i < input_m ; counter_i++)
			scanf("%d", &score_P[counter_i]);
		
		for(counter_i = input_n_min - 1 ; counter_i <= input_n_max - 1 ; counter_i++)
		{
			score_gap =  score_P[counter_i] - score_P[counter_i + 1];
			if(score_gap >= max_score_gap)
			{
				max_score_gap = score_gap;
				//printf("max_score_gap: %d\n", max_score_gap);
				answer_n = counter_i + 1;
			}
		}
		
		printf("%d\n", answer_n);
		
		max_score_gap = 0;
		answer_n = 0;
		
	}
	return 0;
}

