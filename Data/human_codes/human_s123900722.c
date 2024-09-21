#include<stdio.h>

typedef struct
{
	int iti;
	int suuti;
} SAIKORO;


int main(void)
{
	int kaisuu1, kaisuu2, kaisuu3;
	char hougaku[64] = {0};
	char kari1;
	SAIKORO date[6];
	SAIKORO kari2;

	kaisuu2 = 0;

	for (kaisuu1 = 0; kaisuu1 < 6; kaisuu1++)
	{
		date[kaisuu1].iti = kaisuu1 + 1;
		//printf("%d ", date[kaisuu1].iti);
	}
	scanf("%d %d %d %d %d %d ", &date[0].suuti, &date[1].suuti, &date[2].suuti, &date[3].suuti, &date[4].suuti, &date[5].suuti);
	scanf("%s", hougaku);
	while (kaisuu1 != 0)
	{
		kari1 = hougaku[kaisuu2];
		kaisuu2++;
		if (kari1 == 0)
		{
			for (kaisuu3 = 0; kaisuu3 < 64; kaisuu3++)
			{
				hougaku[kaisuu3] = 0;
			}
			break;
		}
		else
		{
			if (kari1 == 'E')
			{
				kari2 = date[3];
				date[3] = date[0];
				date[0] = date[2];
				date[2] = date[5];
				date[5] = kari2;
			}
			if (kari1 == 'W')
			{
				kari2 = date[2];
				date[2] = date[0];
				date[0] = date[3];
				date[3] = date[5];
				date[5] = kari2;
			}
			if (kari1 == 'S')
			{
				kari2 = date[4];
				date[4] = date[5];
				date[5] = date[1];
				date[1] = date[0];
				date[0] = kari2;
			}
			if (kari1 == 'N')
			{
				kari2 = date[1];
				date[1] = date[5];
				date[5] = date[4];
				date[4] = date[0];
				date[0] = date[1];
			}
		}
	}
	printf("%d\n", date[0].suuti);


	return 0;
}
