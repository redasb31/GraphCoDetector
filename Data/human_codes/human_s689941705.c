#include<stdio.h>
#include<stdlib.h>

#define INF 999999
#define MAX_M 20
#define MAX_PAY 50000

int min(int, int);

int main(){

    /* 変数定義 */
    int payment;                // 支払金額
    int m;                      // コインの種類数
    int coin[MAX_M];            // コインの額面
    int cost[MAX_PAY+1];   // 使用する最小のコイン枚数
    int i, j;

    /* 入力 */
    scanf("%d %d", &payment, &m);
    
    /*
    coin = (int *)malloc(m * sizeof(int));
    cost = (int **)malloc(m * sizeof(int *));
    for(i = 0; i <= payment; i++){
        cost[i] = (int *)malloc((payment + 1) * sizeof(int));
    }
    */

    for(i = 0; i < m; i++) scanf("%d", &coin[i]);

    /* 初期化 */
    cost[0] = 0;
    for(j = 1; j <= payment; j++){
       cost[j] = INF;
    }

    /* 動的計画法で問題を解く */
    /* cost[i][j] = i番目までのコインを使って、金額jを払うのに使用するコインの最小枚数 */
    for(i = 0; i < m; i++){
        for(j = coin[i]; j <= payment; j++){
            cost[j] = min(cost[j], cost[j - coin[i]] + 1);
        }
    }

    /* 出力 */
    /*
    for(j = 0; j <= payment; j++){
        printf("%d ", cost[j]);
    }
    printf("\n");
    */
    
    printf("%d\n", cost[payment]);

    return 0;
}

int min(int x, int y){
    int ans;
    
    ans = x < y ? x : y;

    return ans;
}
