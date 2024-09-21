#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    char s[n][51];
    for(int i=0; i<n; i++){
        scanf("%s", s[i]);
    }

    int i=0, c[n][26];
    for(int j=0; j<n; j++){
        for(int k=0; k<26; k++){
            c[j][k]=0;
        }
    }

    i=0;
    while(i<n){
        int j=0;
        while('a'<=s[i][j]&&s[i][j]<='z'){
            switch(s[i][j]){
                case 'a':
                    c[i][0]++;
                    break;
                case 'b':
                    c[i][1]++;
                    break;
                case 'c':
                    c[i][2]++;
                    break;
                case 'd':
                    c[i][3]++;
                    break;
                case 'e':
                    c[i][4]++;
                    break;
                case 'f':
                    c[i][5]++;
                    break;
                case 'g':
                    c[i][6]++;
                    break;
                case 'h':
                    c[i][7]++;
                    break;
                case 'i':
                    c[i][8]++;
                    break;
                case 'j':
                    c[i][9]++;
                    break;
                case 'k':
                    c[i][10]++;
                    break;
                case 'l':
                    c[i][11]++;
                    break;
                case 'm':
                    c[i][12]++;
                    break;
                case 'n':
                    c[i][13]++;
                    break;
                case 'o':
                    c[i][14]++;
                    break;
                case 'p':
                    c[i][15]++;
                    break;
                case 'q':
                    c[i][16]++;
                    break;
                case 'r':
                    c[i][17]++;
                    break;
                case 's':
                    c[i][18]++;
                    break;
                case 't':
                    c[i][19]++;
                    break;
                case 'u':
                    c[i][20]++;
                    break;
                case 'v':
                    c[i][21]++;
                    break;
                case 'w':
                    c[i][22]++;
                    break;
                case 'x':
                    c[i][23]++;
                    break;
                case 'y':
                    c[i][24]++;
                    break;
                case 'z':
                    c[i][25]++;
                    break;
            }
            j++;
        }
        i++;
    }

    int canuse[26];

    for(int j=0; j<26; j++){
        canuse[j]=c[0][j];
    }
    for(int j=1; j<n; j++){
        for(int k=0; k<26; k++){
            if(canuse[k]>c[j][k]){
                canuse[k]=c[j][k];
            }
        }
    }

    for(int j=0; j<26; j++){
        for(int k=0; k<canuse[j]; k++){
            printf("%c", 'a'+j);
        }
    }

    printf("\n");
    return 0;
}
