#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*n+(j))

char *buf=NULL;
char *pointer=NULL;
void init(int maxLen){
  buf=(char *)malloc(maxLen*sizeof(char));
  pointer=buf;
}

inline void print(char c){
  *pointer++=c;
}

inline void printPositiveInt(int64 n){
  char s[20];
  int p=0;
  while(n>=10){
    s[p++]='0'+n%10;
    n/=10;
  }
  s[p]='0'+n;
  while(p>=0) print(s[p--]);
}

void run(void){
  const int n=500;
  int *l=(int *)malloc(sizeof(int)*(n+1));
  int *r=(int *)malloc(sizeof(int)*(n+1));
  int *index=(int *)malloc(sizeof(int)*(n+1));
  {
    int p=0;
    int k=n;
    while(k>=0){
      index[k]=p++;
      k-=2;
    }
    k=(k==-2?1:0);
    while(p<n+1){
      index[k]=p++;
      k+=2;
    }
  }
  int lp=0;
  int rp=0;
  int i=2;
  while(lp<n+1){
    l[index[lp++]]=i++;
  }
  while(rp<n+1){
    r[index[rp++]]=i++;
  }
  int64 *board=(int64 *)malloc(sizeof(int64)*n*n);
  int j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if((i+j)%2==0){
	board[POS(i,j)]=l[(i+j)/2]*r[((n-i)+j)/2];
      } else {
	int64 local=(int64)l[(i+j)/2]*l[(i+j)/2+1]*r[((n-i)+j)/2]*r[((n-i)+j)/2+1];
	board[POS(i,j)]=local+1;
      }
    }
  }
  init(15+(1+15)*(n-1)+1);
  int m;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    pointer=buf;
    printPositiveInt(board[POS(i,0)]);
    for(j=1;j<m;j++){
      print(' ');
      printPositiveInt(board[POS(i,j)]);
    }
    print('\0');
    puts(buf);
  }
}

int main(void){
  run();
  return 0;
}
