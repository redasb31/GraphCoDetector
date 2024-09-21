#include<stdio.h>
int r,ord[100010],low[100010],br[100010],kan[100010],isb[200010];
int ta[100010],to[200010],nt[200010],ed[100010];
long long smco[100010],maco[100010];
long long MIN(long long a,long long b){return a<b?a:b;}
long long MAX(long long a,long long b){return a>b?a:b;}
void cdfs(int s,int *p){//printf("s%d %d\n",s,r);
  int i;
  ord[s]=low[s]=r++;
  for(i=ta[s];i+1;i=nt[i]){
    if(p[to[i]]==-1){
      p[to[i]]=s;
      ed[to[i]]=i;
      cdfs(to[i],p);
      low[s]=MIN(low[s],low[to[i]]);
    }
    else if(to[i]-p[s])low[s]=MIN(low[s],ord[to[i]]);
  }
}
void arpo(int v){
  int p[100010],ans=0,c=0,i,j,f[100010]={0};
  for(i=0;i<v;i++)p[i]=-1;
  cdfs(p[0]=0,p);
  for(i=1;i<v;i++){
    if(p[i]){
      if(ord[p[i]]<=low[i])f[p[i]]=1;
    }
    else c++;
  }
  if(c>1)f[0]=1;
  for(i=0;i<v;i++){
    if(f[i])kan[i]=1;
  }
}
//?????£?????§?????????
int brig(int v){
  int p[100010],ans=0,co=0,i,j;
  for(i=0;i<v;i++)p[i]=-1;
  for(i=r=p[0]=0;i<v;i++){
    if(r<v)cdfs(i,p);
  }
  for(i=1;i<v;i++){//???????????????????´?????????????
    if(ord[p[i]]<low[i])br[co++]=ed[i];
  }
  return co;
}
int deadv[100010],deade[100010],used[100010];
long long sum=0,d[100010],dd[100010];
void f(int s,int g){
  int i;
  if(kan[s]||used[s])return ;
  used[s]=1;
  for(i=ta[s];i+1;i=nt[i])f(to[i],g);
  if(s-g){
    if(ta[s]+1){
      for(i=ta[s];nt[i]+1;i=nt[i]);
      nt[i]=ta[g];
      ta[g]=ta[s];
    }
    deadv[s]=1;
    dd[g]+=dd[s];
  }
}
long long dfs(int s){//printf("!%d %lld\n",s,cost[s]);
  int i;
  if(deadv[s])return 0;
  deadv[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(deade[i]||deadv[to[i]])continue;
    r=dfs(to[i]);
    smco[s]+=r;
    maco[s]=MAX(maco[s],r);
  }//printf("%d %lld\n",s,cost[s]);
  return smco[s]+dd[s];
}
int main(){
  int n,m,i,a,b,c=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    ta[i]=-1;
    scanf("%lld",&d[i]);
    sum+=d[i];
    dd[i]=d[i];
  }
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    a--;
    b--;
    nt[i  ]=ta[to[i+m]=a];
    nt[i+m]=ta[to[i  ]=b];
    ta[a]=i;
    ta[b]=i+m;
  }
  arpo(n);
  //for(i=0;i<n;i++)printf("%d %d\n",i+1,kan[i]);printf("\n");//OK
  c=brig(n);
  
  for(i=0;i<c;i++){
    isb[br[i]]=isb[(br[i]+m)%(2*m)]=1;
  }


  
  for(i=0;i<2*m;i++){//printf("%d\n",br[i]);//OK
    if(isb[i])continue;
    if(kan[to[i]]&&kan[to[(i+m)%(2*m)]]){
      deade[i]=deade[(i+m)%(2*m)]=1;
    }
  }//printf("\n");
  //for(i=0;i<m;i++)printf("%d %d\n",i,deade[i]);printf("\n");//OK
  for(i=0;i<n;i++)f(i,i);
  //for(i=0;i<n;i++)printf("%d %d\n",i+1,deadv[i]);printf("\n");
  for(i=0;deadv[i];i++);//printf("%d\n\n",i);
  dfs(i);
  //for(i=0;i<n;i++)printf("%d %lld\n",i+1,smco[i]);printf("\n");
  //for(i=0;i<n;i++)printf("%lld %lld %d\n",sum,smco[i],kan[i]);
  for(i=0;i<n;i++){
    if(kan[i]){
      printf("%lld\n",MAX(maco[i],sum-smco[i]-d[i]));
    }
    else printf("%lld\n",sum-d[i]);
  }
  return 0;
}