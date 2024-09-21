#include <cstdio>
#include <list>

std::list<int> G[100000];
int mark[100000];

std::list<int> cs;
int iso;

int dfs(int i, int c, int b){
  for(int j : G[i]){
    if(mark[j]&&mark[j]!=-c) b = 0;
    if(!mark[j]){
      mark[j]=-c;
      b &= dfs(j, -c, b);
    }
  }
  return b;
}

int dfs0(int i, int c, int b){
  iso=1;
  for(int j : G[i]){
    if(mark[j]&&mark[j]!=-c) b = 0;
    if(!mark[j]){
      mark[j]=-c;
      b &= dfs(j, -c, b);
      iso=0;
    }
  }
  return b;
}

long long int c(int n){
  int ans=0;
  int ans2=0;
  int ans0=0;
  while(1){
    int i, j;
    for(i=0;i<n;i++){
      if(!mark[i]) break;
    }
    if(i==n){
      ans-=ans2;
      return (long long) ans*ans+(long long) ans2*ans2 + (ans0 ? (long long)(2*n-iso)*iso : 0);
    }
    mark[i] = 1;
    ans++;
    j=dfs0(i, 1, 1);
    ans2+=j&~iso;
    ans0+=iso;
  }

}
int main(){                                                                                                                                                                                                                  
  int i, n, m;
  std::scanf("%d%d", &n, &m);

  for(i=0;i<m;i++){
    int a, b;
    std::scanf("%d%d", &a,&b);
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  printf("%lld\n", c(n));
  return 0;
}
