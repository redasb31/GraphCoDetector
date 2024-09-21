#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
int acs(const void *a, const void *b){return *(int*)a - *(int*)b;} /* 1,2,3,4.. */
int des(const void *a, const void *b){return *(int*)b - *(int*)a;} /* 8,7,6,5.. */
#define min(a,b) (a < b ? a: b)
#define max(a,b) (a > b ? a: b)

#define MAXN (2500)
#define MOD (1000000007)


typedef struct list
{
    int val;
    struct list* next;
}list;

list* to[5000];
list* ot[5000];

typedef struct
{
    int a;
    int b;
    int c;
}edge;

edge es[5000];

bool reach1[MAXN];
bool reachN[MAXN];
bool ok[MAXN];

void dfs1(int i)
{
    if(reach1[i]) return;
    reach1[i] = true;
    list* l = to[i];
    while(l!=NULL)
    {
        dfs1(l->val);
        l = l->next;
    }
}

void dfsN(int i)
{
    if(reachN[i]) return;
    reachN[i] = true;
    list* l = ot[i];
    while(l!=NULL)
    {
        dfsN(l->val);
        l = l->next;
    }
}

int main(void)
{
    int n,m,p;

    scanf("%d %d %d",&n,&m,&p);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a--;
        b--;
        c -= p;
        c *= -1;

        list* l = malloc(sizeof(list));
        l->val = b;
        l->next = to[a];
        to[a] = l;

        l = malloc(sizeof(list));
        l->val = a;
        l->next = ot[b];
        ot[b] = l;

        es[i].a = a;
        es[i].b = b;
        es[i].c = c;
    }

    //関係のないノード検出
    dfs1(0);
    dfsN(n-1);
    for(int i=0;i<n;i++) ok[i] = reach1[i] && reachN[1];

    //ベルマンフォード
    int bf[n];
    bf[0] = 0;
    for(int i=1;i<n;i++) bf[i] = INT_MAX-200000; //重みを足すので
    int step = 0;
    bool update = true;
    while(update)
    {
        update = false;
        for(int i=0;i<m;i++)
        {
            if(ok[es[i].a] && ok[es[i].b])
            {
                int n = bf[es[i].a] + es[i].c;
                if( n < bf[es[i].b])
                {
                    bf[es[i].b] = n;
                    update = true;
                }
            }
        }
        step++;
        if(step > n)
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", max( -bf[n-1],0));

    return 0;
}



