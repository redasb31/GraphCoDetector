/*2019/07/29 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
typedef long long int ll;
void llswap(ll *x,ll *y){ll temp;temp=*x;*x=*y;*y=temp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}

typedef struct{
    int par;
    int l;
    int r;
    int sum;
}tree_t;

int asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int desc(const void *a,const void *b){return *(int*)b-*(int*)a;}
/*
int asc_t(const void *a,const void *b){return ((user_t*)a)->score - ((user_t*)b)->score;}
int desc_t(const void *a,const void *b){return ((user_t*)b)->score - ((user_t*)a)->score;}
*/

void search(tree_t*,int,int);
int main(){
    int n,q;
    static int a[300000],b[300000];
    static int p[300000],x[300000];
    static tree_t tree[200000];

    for(int i=0;i<200000;i++){
        tree[i].l=tree[i].r=-1;
        tree[i].sum=0;
    }

    scanf("%d %d",&n,&q);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]==1){
            tree[a[i]-1].par=a[i]-1;
        }
        if(tree[a[i]-1].l==-1){
            tree[a[i]-1].l=b[i]-1;
            tree[tree[a[i]-1].l].par=a[i]-1;
        }else{
            tree[a[i]-1].r=b[i]-1;
            tree[tree[a[i]-1].r].par=a[i]-1;
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d %d",&p[i],&x[i]);
    }

    for(int i=0;i<n;i++){
        //printf("i:%d par:%d l:%d r:%d\n",i,tree[i].par,tree[i].l,tree[i].r);
    }

    for(int i=0;i<q;i++){
        tree[p[i]-1].sum+=x[i];
        //printf("cnt:%d\n",i);
        //printf("i:%d sum:%d\n",p[i],tree[p[i]-1].sum);
        if(tree[p[i]-1].l!=-1)search(tree,tree[p[i]-1].l,x[i]);
        if(tree[p[i]-1].r!=-1)search(tree,tree[p[i]-1].r,x[i]);
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",tree[i].sum);
    }
    printf("%d\n",tree[n-1].sum);
    return 0;
}

void search(tree_t *tree,int next,int x){
    tree[next].sum+=x;
    //printf("i:%d sum:%d\n",next+1,tree[next].sum);
    if(tree[next].l!=-1)search(tree,tree[next].l,x);
    if(tree[next].r!=-1)search(tree,tree[next].r,x);
    
}