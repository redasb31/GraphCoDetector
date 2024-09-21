#include <stdio.h>
#define SIZE 3
#define N 3
int main(void) {
    int i,j,flag;
    char board[SIZE*SIZE];
    while (scanf("%s\n",board)!=EOF) {
        flag =0;
        for(i=0;i<SIZE*SIZE;i++){
            if (i+(N-1)*SIZE<=i%SIZE+SIZE*(SIZE-1)) {
                if (board[i]=='o'||board[i]=='x') {
                    for(j=0;j<N-1;j++) {
                        if (board[i+j*SIZE]!=board[i+(j+1)*SIZE]) break;
                        if (j==N-2) flag=1;
                    }
                }
            }
            if (i+N-1<=(i/SIZE)*SIZE+(SIZE-1)) {
                if (board[i]=='o'||board[i]=='x') {
                    for(j=0;j<N-1;j++) {
                        if (board[i+j]!=board[i+(j+1)]) break;
                        if (j==N-2) flag=1;
                    }
                }
            }
            if (i+(N-1)*(SIZE+1)<=SIZE*SIZE-1) {
                if (board[i]=='o'||board[i]=='x') {
                    for(j=0;j<N-1;j++) {
                        if (board[i+j*(SIZE+1)]!=board[i+(j+1)*(SIZE+1)]) break;
                        if (j==N-2) flag=1;
                    }
                }
            }
            if (i+(N-1)*(SIZE-1)<=SIZE*(SIZE-1)&&((i+(N-1)*(SIZE-1))/SIZE-i/SIZE==N-1)) {
                if (board[i]=='o'||board[i]=='x') {
                    for(j=0;j<N-1;j++) {
                        if (board[i+j*(SIZE-1)]!=board[i+(j+1)*(SIZE-1)]) break;
                        if (j==N-2) flag=1;
                    }
                }
            }
            if (flag==1) {
                printf("%c\n",board[i]);
                break;
            } else if (i==SIZE*SIZE-1) {
                printf("d\n");
            }
        }
    }
    return 0;
}