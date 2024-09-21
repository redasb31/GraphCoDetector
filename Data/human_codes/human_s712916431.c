#include <stdio.h>
#include <string.h>

char x[1001];
char y[1001];
int matrix[1001][1001];

void LCSlength(int,int);

int main(){
  int q,i;

  for(i=0;i<1001;i++){
    matrix[0][i] = 0;
    matrix[i][0] = 0;
  }

  scanf("%d",&q);


  for(i=0;i<q;i++){
    scanf("%s",x);
    scanf("%s",y);
    LCSlength(strlen(x),strlen(y));

    printf("%d\n",matrix[strlen(x)][strlen(y)]);
  }
  
    return 0;
}

void LCSlength(int m,int n){
  int i,j;
  
   for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
      if(x[i-1] == y[j-1]) matrix[i][j] = matrix[i-1][j-1] + 1;

      else if( matrix[i-1][j] >  matrix[i][j-1])  matrix[i][j] = matrix[i-1][j];
      else  matrix[i][j] = matrix[i][j-1];
    }
   }
}