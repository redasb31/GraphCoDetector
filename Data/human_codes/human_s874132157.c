#include<stdio.h>
int t[1000000], p[10000];
int check(int i, int q){
    int j;
    for(j=1; j<q; j++)if(t[j+i]!=p[j])return 0;
    return 1;
}
int main(){
    int i, l=0, q=0;
    while((t[l++]=getchar())!='\n'){}
    while((p[q++]=getchar())!='\n'){}
    for(i=0; i<l-q+1; i++){
        if(t[i]!=p[0])continue;
        else if(check(i, q-1))printf("%d\n", i);
    }
    return 0;
}