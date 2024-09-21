#include<stdio.h>

int main(void)
{
  int N, i, p[9], memory, answer;
  scanf("%d", &N);

  scanf("%d", &p[0]);
  answer += p[0];
  memory = p[0];

  for(i = 1; i < N - 1; i ++){
    scanf("%d", &p[i]);
    answer += p[i];
    if(p[i] > p[i - 1]){
      memory = p[i];
    }
  }

  printf("%d", answer - memory / 2);

}
