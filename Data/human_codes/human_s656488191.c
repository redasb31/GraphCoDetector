#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//????????¢??°????????????MAX???
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//?????\??¢??°
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//??????????????¢??°
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int ta[100010],nt[400010],to[400010],co[400010];
//????????°??????
void mkls(int v,int e,int *a,int *b,int *c){
  int i;
  for(i=0;i<v;i++)ta[i+1]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[b[i]]=i+e]=co[ta[a[i]]=i]=c[i];
  }
}
void prls(int v){
  int i,j;
  for(i=0;i<v;i++){
    printf("%d:",i+1);
    for(j=ta[i+1];j+1;j=nt[j])printf("%d,%d ",to[j],co[j]);
    printf("\n");
  }
  printf("\n");
}
int MAX(int a,int b){return a<b?b:a;}
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,k,a[200010],b[200010],c[200010],d[100010],e[100010],f[100010];
  int q[100010],t,r,i,j;
  scanf("%d %d %d",&n,&m,&k);
  for(i=0;i<m;i++)scanf("%d %d",&a[i],&b[i]);
  for(i=0;i<m;i++)c[i]=1e9;
  for(i=0;i<k;i++){
    scanf("%d",&j);
    c[j-1]=i+1;
  }
  mkls(n,m,a,b,c);
  //prls(n);
  q[t=0]=1;
  for(i=0;i<n;i++)d[i+1]=1e9;
  for(i=0;i<n;i++)e[i+1]=0;
  d[1]=0;
  e[1]=1e9;
  for(r=1;r-t;t++){//printf("%d\n",q[t]);
    hin(e[q[t]]);
    for(i=ta[q[t]];i+1;i=nt[i]){
      if(d[to[i]]<d[q[t]]+1)continue;
      if(d[to[i]]>d[q[t]]+1)q[r++]=to[i];
      d[to[i]]=d[q[t]]+1;
      e[to[i]]=MAX(e[to[i]],MIN(e[q[t]],co[i]));
    }
  }
  for(i=0;i<n;i++)f[i]=N[hout()];
  //for(i=0;i<n;i++)printf("%d ",f[i]);printf("\n");
  for(i=j=0;i<k;i++){
    while(f[j]<=i+1)j++;
    printf("%d\n",j);
  }
  return 0;
}