#include<stdio.h>

void sort(int *a);

int main(void)
{
	int n,k;
	int i,j;
	char tmp[11];
	int cnt[26] = {0};
	int result= 0;
	
	scanf("%d %d\n", &n, &k);
	
	for(i = 0; i < n; i++){
		scanf("%s", tmp);
		cnt[tmp[0]-'A']++;
	}
	
	while(1){
		sort(cnt);
		for(i = 0; i < k;i++){
			cnt[i]--;
			if(cnt[i] < 0){
				printf("%d\n", result);
				return 0;
			}
		}
		result++;
	}
	
}

void sort(int *a){
	int i,j;
	int tmp;
	int max,num;
	
	for(i = 0; i < 26; i++){
			max= 0;
			num = i;
		for(j = i; j < 26; j++){
			if(a[j]>max){
				num = j;
				max = a[j];
			}
		}
		tmp = a[num];
		a[num] = a[i];
		a[i] = tmp;
	}
}
