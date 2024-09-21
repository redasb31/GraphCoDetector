#include <stdio.h>
 
 #define N 8
 #define FREE 0
 #define NOT_FREE 1
 
 void putQueen(int);
 void PrintBoard(void);
 
 int Queen[N][N];
 int dpos[2*N-1];
 int dneg[2*N-1];
 int row[N];
 int col[N];
 
 int main(){
 
 int i;
 int n;
 int q_row;
 int q_col;
 
 scanf("%d",&n);
 
 for(i=0;i<n;i++){
 scanf("%d%d",&q_row,&q_col);
 Queen[q_row][q_col] = NOT_FREE;
 }
 
 putQueen(0);
 
   return 0;
}
void putQueen(int i){
 
 int j;
 
 if(i==N){
 PrintBoard();
 return;
 }
 
 for(j=0;j<N;j++){
 if(col[j]==NOT_FREE || dpos[i+j]==NOT_FREE || dneg[i-j+N-1]==NOT_FREE) continue;
 
 row[i] = j;
 col[j] = dpos[i+j] = dneg[i-j+N-1] = NOT_FREE;
 putQueen(i+1);
 
 col[j] = dpos[i+j] = dneg[i-j+N-1] = FREE;
 }
 
}
void PrintBoard(void){
 
 int i;
 int j;
 
 for(i=0;i<N;i++){
  for(j=0;j<N;j++){
 
 if(Queen[i][j]==NOT_FREE){
    if(row[i]!=j) return;
    }
 
   }
  }
 
 for(i=0;i<N;i++){
  for(j=0;j<N;j++){
 
 if(row[i]==j){
  printf("Q");
   }
 
 else{
  printf(".");
   }
 
   }
  printf("\n");
   }
 }