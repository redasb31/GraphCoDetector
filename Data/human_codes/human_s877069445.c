#include <stdio.h>
#include <stdbool.h>

int ans[1500];
int P, Q, A, N;
int tmpans = 0;

// nume 現在の分子,　deno 現在の分母, x 追加した分母の値, depth 今の再起の深さ(1回目を0としている)
void dps(int nume, int deno, int x, int depth){
    // P/Q < nume/demo ならこれ以上確認しない
    if(P * deno < Q * nume) return;
    // P/Q = nume/demoなら答えに1を追加
    if(P * deno == Q * nume) {tmpans++; return;}
    // 深さの限度に達したら終了
    if(depth == N) return;

    // Aの条件を超えないまで分母の値を増やして再起関数に突っ込む
    for(int i = x; i * deno <= A; i++){
        dps(nume * i + deno, deno * i, i, depth + 1);
    }
}

int main(){
    int i = 0;

    for(i = 0; i < 1500; i++){
        ans[i] = -1;
    }
    i = 0;
    while(true){
        scanf("%d %d %d %d", &P, &Q, &A, &N);
        if(P == 0 && Q == 0) break;
        tmpans = 0;

        // 0/1から始める, 分母の値は1, 初期の深さは0
        dps(0, 1, 1, 0);

        ans[i] = tmpans;
        i++;
    }


    for(int i = 0; i < 1500; i++){
        if(ans[i] != -1) printf("%d\n", ans[i]);
        else break;
    }   

    return 0;
}
