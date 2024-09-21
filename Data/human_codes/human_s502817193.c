#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    int U;
    int A;
    int P;
    int score;
} DATA;

int comp(const void *a, const void *b)
{
    int score;
    
    score = (*(DATA *)b).score - (*(DATA *)a).score;

    if (score != 0){
        return (score);
    }
    return ((*(DATA *)a).ID - (*(DATA *)b).ID);
}


int main(void)
{
    int n;
    int u[1001];
    DATA team[300];
    int i;
    int teams;
    
    while (1){
        memset(u, 0, sizeof(u));

        scanf("%d", &n);
        if (n == 0){
            break;
        }
        
        for (i = 0; i < n; i++){
            scanf("%d%d%d%d", &team[i].ID, &team[i].U, &team[i].A, &team[i].P);
            
            team[i].score = team[i].A * 1000000 + 100000 - team[i].P;
        }
        
        qsort(team, n, sizeof(DATA), comp);
#if 0
        for (i = 0; i < n; i++){
            printf(":%d %d %d %d %d\n", team[i].ID, team[i].U,team[i].A,team[i].P,team[i].score);
        }
#endif        
        teams = 0;
        for (i = 0; i < n; i++){
            if (teams < 10){
                if (u[team[i].U]++ < 3){
                    printf("%d\n", team[i].ID);
                    teams++;
                }
            }
            else if (teams < 20){
                if (u[team[i].U]++ < 2){
                    printf("%d\n", team[i].ID);
                    teams++;
               }
            }
            else if (teams < 26){
                if (u[team[i].U]++ < 1){
                    printf("%d\n", team[i].ID);
                    teams++;
                }
            }
        }
    }
    
    return (0);
}

