/*2019/10/19 */
/*template*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
#define MIN 999999999
#define MAX -999999999
typedef long long int ll;
typedef unsigned long long int ull;
void llswap(ll *x,ll *y){ll tmp;tmp=*x;*x=*y;*y=tmp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){if(*(int*)a < *(int*)b)return -1;else if(*(int*)a == *(int*)b)return 0;else return 1;}
int desc(const void *a,const void *b){if(*(int*)a < *(int*)b)return 1;else if(*(int*)a == *(int*)b)return 0;else return -1;}
int llasc(const void *a,const void *b){if(*(ll*)a < *(ll*)b)return -1;else if(*(ll*)a == *(ll*)b)return 0;else return 1;}
int lldesc(const void *a,const void *b){if(*(ll*)a < *(ll*)b)return 1;else if(*(ll*)a == *(ll*)b)return 0;else return -1;}
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
 
//int asc_t(const void *a,const void *b){if(((pair_t*)a)->d < ((pair_t*)b)->d)return -1;else if(((pair_t*)a)->d == ((pair_t*)b)->d)return 0;else return 1;}
//int asc_t(const void *a,const void *b){if(((pair_t*)a)->d < ((pair_t*)b)->d)return 1;else if(((pair_t*)a)->d == ((pair_t*)b)->d)return 0;else return -1;}
double to_deg(double r) {return r * 180.0 / (atan(1.0) * 4.0);}

int main(){
    int n,a,x,y;
    scanf("%d",&n);

    int list[100][100]={{}},person_false[100]={};
    
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        for(int j=0;j<a;j++){
            scanf("%d %d",&x,&y);
            if(y==1)list[i][x]=1;
        }
    }
    
    int cnt=0,max=-1;
    int tmp;
    for(int i=1;i<=n;i++){
        cnt=1;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(list[i][j]==0)continue;
            for(int k=1;k<=n;k++){
                if(list[j][k]==0&&i==k){
                    cnt=0;
                    goto END;
                }
                if(list[j][k])cnt++;
            }
            
        }
        END:
        if(cnt>max)max=cnt;
    }
    printf("%d\n",max);
    return 0;
}