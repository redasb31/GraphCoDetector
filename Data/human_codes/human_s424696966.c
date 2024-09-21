#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
#define rep(i,a) for(i=first[a];i;i=next[i])
using namespace std;
const int maxn=5e5+7;
int i,j,k,l,n,m,ans,x,y,t[maxn*4];
int a[maxn],b[maxn];
int first[maxn*4],last[maxn*4],next[maxn*4],num,c[maxn],d[maxn],an[maxn],e[maxn];
set<int>tt;
void add(int x,int y){
    last[++num]=y,next[num]=first[x],first[x]=num;c[y]++;
}
void insert(int x,int l,int r,int y,int z){//位置上对应新的位置 
    if(l==r){
	    t[x]=z;return;
	}
	int mid=(l+r)/2;
	if(y<=mid)insert(x*2,l,mid,y,z);
	else insert(x*2+1,mid+1,r,y,z);
	t[x]=min(t[x*2],t[x*2+1]);
}
int find(int x,int l,int r,int y,int z){
    if(y>z)return n+1;
    if(l==y&&r==z)return t[x];
	int mid=(l+r)/2;
	if(z<=mid)return find(x*2,l,mid,y,z);
	else if(y>mid)return find(x*2+1,mid+1,r,y,z);
	else return min(find(x*2,l,mid,y,mid),find(x*2+1,mid+1,r,mid+1,z));
}
int main(){
    scanf("%d%d",&n,&k);
    fo(i,1,n)scanf("%d",&a[i]),b[a[i]]=i;
    fo(i,0,4*maxn-1)t[i]=n+1;
    fod(i,n,1){
    	x=find(1,1,n,max(b[i]-k+1,1),b[i]-1);
    	if(x!=n+1)add(b[i],b[x]);
    	x=find(1,1,n,b[i]+1,min(b[i]+k-1,n));
    	if(x!=n+1)add(b[i],b[x]);
    	insert(1,1,n,b[i],i);
	}
	fo(i,1,n)if(!c[i])tt.insert(i);
	while(!tt.empty()){
	    x=*tt.begin();e[++ans]=x;
	    rep(i,x){
		    c[last[i]]--;
		    if(!c[last[i]])tt.insert(last[i]);
		}
	    tt.erase(x);
	}
	fo(i,1,n)an[e[i]]=i;
	fo(i,1,ans)printf("%d\n",an[i]);
}