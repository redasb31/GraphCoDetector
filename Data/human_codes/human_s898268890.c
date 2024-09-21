#include<stdio.h>
long long CO[510][50][2];
long long R=1,C=1,H[1000010],N[1000010];
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
void hin(long long a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int main(){
  int n,m,i,mi,f,a,b,c,nf;
  int ta[510],to[10010],co[10010],nt[10010];
  int id[100010],V[100010],F[100010],u[510][50][2]={};
  long long ans=1e18,v,nv;
  for(i=0;i<510*50;i++)CO[i/50][i%50][0]=CO[i/50][i%50][1]=1e18;
  scanf("%d %d",&n,&m);
  for(i=0;i<=n;i++)ta[i]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a,&b,&c);
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    co[ta[b]=i+m]=co[ta[a]=i]=c;
  }
  /*for(i=1;i<=n;i++){printf("%d:",i);int j;
    for(j=ta[i];j+1;j=nt[j])printf("%d ",to[j]);
    printf("\n");
    }//*/
  scanf("%lld %d %d %d",&v,&a,&b,&c);
  CO[1][v][0]=0;
  mi=1;
  f=0;
  while(u[mi][v][f]-1){//printf("%lld %d %lld %d\n",CO[mi][v][f],mi,v,f);
    u[mi][v][f]=1;
    nv=(a*v+b)%c;
    for(i=ta[mi];i+1;i=nt[i]){
      nf=to[i]==n?1:f;
      if(CO[to[i]][nv][nf]>CO[mi][v][f]+co[i]*v){
	id[R]=to[i];
	V[R]=nv;
	F[R]=nf;
	hin(CO[to[i]][nv][nf]=CO[mi][v][f]+co[i]*v);
      }
    }
    while(u[mi][v][f]&&C-1){
      i=hout();
      mi=id[i];
      v=V[i];
      f=F[i];
    }
  }
  for(i=0;i<50;i++){
    if(ans>CO[1][i][1])ans=CO[1][i][1];
    //printf("%lld\n",CO[1][i][1]);
  }
  printf("%lld\n",ans);
  return 0;
}