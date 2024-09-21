#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int N;
    char s[200001];
    char str[200001];
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
        if(j>0 && str[j]=='R' && str[j-1]!='S'){
            if(str[j-1]=='R'){ 
                str[j - 1] = '2';
                j--;
            }
            else if (str[j - 1] < 80){
                str[j-1] = str[j - 1] + 1;
                j--;
            }
        }
        j++;
    } //jが総数
/*
    printf("\n----");
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
            if (str[q] == 'S')
            {
        
                for (int l = 0; l < N; l++)
                {
                    a[l] = (a[l] * 2) % 3;
                } //3進数の回転
            }
            else
            {
                
                int kk;
                if(str[q]=='R')
                    kk = 1;
                else
                    kk = str[q] - 48;//数にす　る

                    a[0] += kk;
                for (int l = 0; a[l] >= 3; l++)
                {
                    kk = a[l] / 3;
                    a[l] = a[l] % 3;
                    a[l + 1] += kk;
                } //繰り上げ
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