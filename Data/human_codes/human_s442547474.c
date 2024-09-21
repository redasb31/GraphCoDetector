#include <stdio.h>
#include <string.h>

int main(void)
{
    char al[26]={'A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I',
                 'J', 'K', 'L', 'M', 'N','O','P','Q','R', 'S',
                 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char in[10001];
    char out[10001];
    int n,i,j,len;

    scanf("%d", &n);
    scanf("%s", in);

    for(i=0; in[i]!='\0'; i++){
        for(j=0; j<26; j++){
            if(in[i]==al[j]){
                if(j+n<26){
                    out[i] = al[j+n];
                }
                else
                {
                    out[i] = al[(j+n)%26];
                }
            }
        }
    }

    printf("%s\n", out);
}