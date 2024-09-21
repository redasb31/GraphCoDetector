//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int min(int a,int b){if(a<b){return a;}return b;}

long long nCr[64][64]={0};
void calcnCr(){
  nCr[0][0]=1;
  long long i,j;
  for(i=0;i<63;i++){
    for(j=0;j<=i;j++){
      nCr[i+1][j]+=nCr[i][j];
      nCr[i+1][j+1]+=nCr[i][j];
    }
  }
  return;
}

long long res=0,s,t,k;

void rep(int nb,int nv,int lis[],int c){
  int i,bd;
  if(nb==-1){
    long long ce=1;
    bd=min(c,k);
    if(nv&1){ce=-1;}
    for(i=1;i<=bd;i++){
      //printf("<%lld>\n",ce*nCr[c][i]);
      res+=(ce*nCr[c][i]);
    }
    return;
  }
  //printf("<%d %d>:",nb,nv);
  //for(i=0;i<c;i++){printf("[%d]",lis[i]);}printf("\n");
  rep(nb-1,nv,lis,c);
  if((s&(1<<nb))==(t&(1<<nb))){return;}
  int liz[64],lio[64],lzc=0,loc=0;
  for(i=0;i<c;i++){
    if((lis[i]&(1<<nb))){lio[loc]=lis[i];loc++;}
    else{liz[lzc]=lis[i];lzc++;}
  }
  rep(nb-1,nv+1,lio,loc);
  rep(nb-1,nv+1,liz,lzc);
}

int main(void){
  calcnCr();
  int i,j,n,a[64];
  int lis[64],c=0;
  scanf("%d%d%d%d",&n,&k,&s,&t);
  if((s&t)!=s){printf("0\n");return 0;}
  if((s|t)!=t){printf("0\n");return 0;}
  for(i=0;i<n;i++){scanf("%d",&a[i]);}
  for(i=0;i<n;i++){
    if((a[i]&s)!=s){continue;}
    if((a[i]|t)!=t){continue;}
    lis[c]=a[i];c++;
  }
  rep(17,0,lis,c);
  printf("%lld\n",res);
  return 0;
}
