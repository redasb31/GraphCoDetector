#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int ta[1010],to[1000010],nt[1000010],co[1000010],F[1010];
int MF(int s,int t,int e,int min){
  if(s==t||min==0)return min;
  int i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]])continue;
    r=MF(to[i],t,e,MIN(min,co[i]));
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
int Flow(int s,int t,int v,int e,int min){
  while(v--)F[v]=0;
  return MF(s,t,e,min);
}
int maxf(int v,int e,int s,int t){
  int f,r;
  for(f=0;r=Flow(s,t,v,e,1e9);f+=r);
  return f;
}
int main(){
  int n,m,q,l,ans,e,r=0,i,a,b,k;
  scanf("%d %d %d",&n,&m,&q);
  e=m+q;
  for(i=0;i<=n;i++)ta[i]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    nt[r  ]=ta[to[r+e]=a];
    nt[r+e]=ta[to[r  ]=b];
    co[ta[b]=r+e]=co[ta[a]=r]=1;
    r++;
  }/*printf("a\n");
  for(i=0;i<=n;i++){printf("%d:",i);
    for(k=ta[i];k+1;k=nt[k])printf(" %d",to[k]);
    printf("\n");
    }//*/
  ans=maxf(n+1,e,1,n);//printf("%d\n",ans);
  while(q--){
    scanf("%d %d %d",&k,&a,&b);
    if(k==1){
      for(i=ta[a];i+1;i=nt[i]){
	if(to[i]==b)break;
      }
      if(i==-1){
	nt[r  ]=ta[to[r+e]=a];
	nt[r+e]=ta[to[r  ]=b];
	co[ta[b]=r+e]=co[ta[a]=r]=1;
	r++;
      }
      else co[i]=co[(i+e)%(2*e)]=1;
      ans+=Flow(1,n,n+1,e,1);
    }
    else{
      for(k=ta[a];to[k]-b;k=nt[k]);
      if(co[k]==2){
	i=a;
	a=b;
	b=i;
	k=(k+e)%(2*e);
      }
      if(co[k]==1);//co[i]=co[(i+e)%(2*e)]=0;
      else if(MF(a,b,e,1)==0){
	Flow(n,b,n+1,e,1);
	Flow(a,1,n+1,e,1);
	ans--;
      }
      co[k]=co[(k+e)%(2*e)]=0;
    }
    printf("%d\n",ans);
  }
  return 0;
}

