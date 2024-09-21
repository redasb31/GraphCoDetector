#include <stdio.h>
#include <malloc.h>
#include <string.h>

void reverse(char *in, char *out)
{
    int i, j = 0;
    int len = strlen(in);
    for (i = len - 1; i >= 0; i--)
    {
        out[j] = in[i];
        j++;
    }
}

void searchMin(char *in, char *out, int N)
{
    int len = strlen(in);
    int i;
    char *sub = (char *)calloc(N + 1, sizeof(char));
    char *tmp = (char *)calloc(N + 1, sizeof(char));

    memcpy(sub, in, N);

    for (i = 1; i < len - N; i++)
    {
        memset(tmp, 0, N + 1);
        memcpy(tmp, in + i, N);
        if (strcmp(tmp, sub) < 0)
        {
            strcpy(sub, tmp);
        }
    }

    strcpy(out, sub);

    free(sub);
    free(tmp);
}

int main(void)
{
    int N;
    char *S, *U, *MIN;
    char *S_temp, *U_temp;
    int K;
    int count = 1;

    scanf("%d %d", &N, &K);
    S = (char *)calloc(N + 1, sizeof(char));
    S_temp = (char *)calloc(N + 1, sizeof(char));
    U = (char *)calloc(N * 2 + 1, sizeof(char));
    U_temp = (char *)calloc(N * 2 + 1, sizeof(char));
    scanf("%s", S);

    //printf("N = %d, K = %d, S = %s\n", N, K, S);

    while (count < K)
    {
        memset(S_temp, 0, N + 1);
        memset(U, 0, N * 2 + 1);
        memset(U_temp, 0, N * 2 + 1);

        // Uを作成
        reverse(S, S_temp);
        strcat(U, S);
        strcat(U, S_temp);

        // Uの反転文字列を作成
        reverse(U, U_temp);

        // 最小文字列を検索
        searchMin(U_temp, S_temp, N);
        reverse(S_temp, S);

        count++;
    }

    memset(S_temp, 0, N + 1);
    memset(U, 0, N * 2 + 1);
    memset(U_temp, 0, N * 2 + 1);

    // Uを作成
    reverse(S, S_temp);
    strcat(U, S);
    strcat(U, S_temp);

    // 最小文字列を検索
    searchMin(U, S, N);

    printf("%s\n", S);

    free(S);
    free(S_temp);
    free(U);
    free(U_temp);

    return 0;
}