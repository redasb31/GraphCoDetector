#include <stdio.h>
#include <string.h>


#define	ll_int	long long int
#define	SIZE	32


// 引数：表示する配列、反転するか否か
void Disp(int *box, int inversion)
{
	int i;

	for(i = 0; i < SIZE; i++){
		if(inversion){
			if(box[i])
				printf("0");
			else
				printf("1");
		}else
			printf("%d", box[i]);
	}
	printf("\n");
}


int main()
{
	ll_int x, tmp;
	int bit_box[SIZE], bit_box_cpy[SIZE];
	int i;

	scanf("%lld", &x);

	// ビット列初期化
	for(i = 0; i < SIZE; i++)
		bit_box[i] = 0;


	// ビットへ変換
	i = 0;
	while( (tmp = x / 2) >= 1){
		bit_box[(SIZE - 1) - i] = x % 2;
		x = tmp;
		i++;
	}
	bit_box[(SIZE - 1) - i] = x;


	/* 表示 */
	// ビット列
	Disp(bit_box, 0);
	// 反転
	Disp(bit_box, 1);

	// 左シフト
	memcpy(bit_box_cpy, bit_box, sizeof(int) * SIZE);
	for(i = 1; i < SIZE; i++)
		bit_box_cpy[i - 1] = bit_box_cpy[i];
	bit_box_cpy[SIZE - 1] = 0;

	Disp(bit_box_cpy, 0);

	// 右シフト
	memcpy(bit_box_cpy, bit_box, sizeof(int) * SIZE);
	for(i = 31; i > 0; i--)
		bit_box_cpy[i] = bit_box_cpy[i - 1];
	bit_box_cpy[0] = 0;

	Disp(bit_box_cpy, 0);

	return 0;
}
