#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int N;
    char s[20000];
    char str[20000];
    int j = 0;
    int ext;
    scanf("%d %s", &N, s);
    
    int all = (int)pow(3.0, N);
    int max = strlen(s);

    for (int i = 0; i < max; i++)
    {
        str[j] = s[i];
        if (j > 0 && str[j] == 'S' && str[j - 1] == 'S')
            j=j-2;//二つセットで消す
        else if (str[j] == '\0')
            break;
        j++;
    } //jが総数

    /*printf("\n----");
    for (int i = 0; i < j; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n----");
*/
    int a[15];
    for (int i = 0; i < 14; i++)
    {
        a[i] = 0;
    } //初期化
    

    
 
    int count = 0;
    for (int i = 0; i < all; i++)
    {
        ext=i;
        for (int q = 0; q < N; q++)
        {
            a[q] = ext % 3;
            ext = ext / 3;
        } //3進数
        for (int q = 0; q < j; q++)
        {
            if (str[q] == 'R')
            {
                a[0] += 1;
                for (int l = 0; a[l] == 3; l++)
                {
                    a[l] = 0;
                    a[l + 1] += 1;
                } //繰り上げ
            }
            else
            {
                for (int l = 0; l < N; l++)
                {
                    a[l] = (a[l] * 2) % 3;
                } //3進数の回転
            }
           // printf("%d番目の人は今%cで%dへ移動\n", i, str[q], a[0]);
        } //Sとか

        count = 0;
        for (int q = 0; q < N; q++)
        {
            count += a[q] * (int)pow(3.0, q);
        } //3進数で今何番地か

        
        printf("%d ",count%all);
       // member[i] = count % all;
    }

    printf("\n");
    return 0;
}