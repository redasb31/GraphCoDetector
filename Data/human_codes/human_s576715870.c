#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

typedef struct node{
    int c;
    int id;
}node;

int cmpAsc(const void* a, const void* b){
    int x = ((node*)a)->c, y = ((node*)b)->c;
    if(x > y){
        return 1;
    }
    if(x < y){
        return -1;
    }
    int p = ((node*)a)->id, q = ((node*)b)->id;
    if(p > q){
        return 1;
    }
    if(q < p){
        return -1;
    }
    return 0;
}

int binarySearch_l(node* p, int n, int target){
    int l = 0, r = n-1;
    int m = (l+r+1)/2;
    while(l < r){
        if((p + m)->c <= target){
            l = m;
        }else{
            r = m-1;
        }
        m = (l+r+1)/2;
    }
    if((p+m)->c != target){
        return -1;
    }
    return m;
}
int binarySearch_r(node* p, int n, int target){
    int l = 0, r = n-1;
    int m = (l+r)/2;
    while(l < r){
        if(target <= (p + m)->c){
            r = m;
        }else{
            l = m+1;
        }
        m = (l+r)/2;
    }
    if((p+m)->c != target){
        return -1;
    }
    return m;
}
int binarySearch_id(node* p, int l, int r, int target){
    int m = (l+r)/2;
    while(l < r){
        if(target < (p + m)->id){
            r = m;
        }else{
            l = m+1;
        }
        m = (l+r)/2;
    }
    return m;
}

int main(){
    char s[100001], t[100001];
    scanf("%s", s);
    scanf("%s", t);
    int s_len = strlen(s), t_len = strlen(t);
    node a[s_len];
    rep(i, 0, s_len){
        a[i].c = s[i] - 'a';
        a[i].id = i;
    }
    qsort(a, s_len, sizeof(node), cmpAsc);
    lld ans;
    int f = 0;
    int id = -1, target = t[0] - 'a';
    rep(i, 0, s_len){
        if(target == a[i].c){
            id = a[i].id;
            f = 1;
            break;
        }
    }
    ans = id+1;
    rep(i, 1, t_len){
        target = t[i] - 'a';
        int l, r;
        l = binarySearch_r(a, s_len, target);
        r = binarySearch_l(a, s_len, target);
        if(l == -1 || r == -1){
            f = 0;
            break;
        }
        int buf = binarySearch_id(a, l, r, id);
        if(a[buf].id <= id){
            buf = l;
        }
        if(id < a[buf].id){
            ans += a[buf].id - id;
        }else{
            ans += s_len + a[buf].id - id;
        }
        id = a[buf].id;
    }
    if(f){
        printf("%lld", ans);
    }else{
        printf("-1");
    }

    return 0;
}