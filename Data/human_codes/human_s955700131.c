#include <stdio.h>
#include <string.h>

#define QMAX (100000)

typedef struct {
    int tx, ty;
    int now;
} FROG;

FROG queue[QMAX + 1];
int head, tail;

void enq(FROG x)
{
    queue[tail++] = x;
    if (tail == QMAX){
        tail -= QMAX;
    }
}

FROG deq(void)
{
    FROG x = queue[head++];
    if (head == QMAX){
        head -= QMAX;
    }
    return (x);
}

int main(void)
{
    int dx[] = {-2, -2, -2, -1, -1, 0,  0, 1,  1, 2, 2,  2};
    int dy[] = { 1,  0, -1,  2, -2, 2, -2, 2, -2, 1, 0, -1};
    FROG add, temp;
    FROG spray[10];
    char v[10][10][11];
    int ddx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int ddy[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
    int tarx, tary;
    int n;
    int i, j;
    int flag;
    
    while (1){
        scanf("%d%d", &add.tx, &add.ty);
        
        if (add.tx + add.ty == 0){
            break;
        }
        
        add.now = 0;
        
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            scanf("%d%d", &spray[i].tx, &spray[i].ty);
        }
        memset(v, 0, sizeof(v));
        head = tail = 0;
        enq(add);
        
        flag = 1;
        while (head != tail){
            temp = deq();
            for (i = 0; i < 9; i++){
                tary = spray[temp.now % n].ty + ddy[i];
                tarx = spray[temp.now % n].tx + ddx[i];
                if (tarx < 0 || tarx >= 10 || tary < 0 || tarx >= 10){
                    continue;
                }
                for (j = 0; j < 12; j++){
                    add.tx = temp.tx + dx[j];
                    add.ty = temp.ty + dy[j];
                    add.now = temp.now;
                    
                    if (add.tx < 0 || add.tx >= 10 || add.ty < 0 || add.ty >= 10){
                        continue;
                    }
                    
                    if (tary == add.ty && tarx == add.tx && add.now == n && v[add.now % n][add.ty][add.tx] == 1){
                        printf("OK\n");
                        flag = 0;
                        break;
                    }
                    else if (tary == add.ty && tarx == add.tx){
                        v[add.now][add.ty][add.tx] = 1;
                        add.now++;
                        enq(add);
                    }
                }
                if (flag == 0){
                    break;
                }
            }
            if (flag == 0){
                break;
            }
        }
        if (flag == 1){
            printf("NA\n");
        }
    }
    
    return (0);
}