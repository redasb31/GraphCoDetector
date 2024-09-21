#include <stdio.h>
#include <string.h>

char a[32][32], b[32][32], t[32][32];
int h, w, n;

int func(void)
{
    int i, j, k, l, res;
    memcpy(b, a, sizeof(a));
    for(j=0;j<w;++j) {
        k=h;
        for(i=h-1;i>=0;--i) if (b[i][j]!='.') a[--k][j]=b[i][j];
        for(i=k-1;i>=0;--i) a[i][j]='.';
    }
    memcpy(b, a, sizeof(a));

    for(i=0;i<h;++i) for(j=0;j<w;++j) if (a[i][j]!='.') {
        for(k=0;j+k<w && a[i][j]==a[i][j+k];++k);
        if (k>=n)
            for(l=0;l<k;++l) b[i][j+l]='.';
        j+=k-1;
    }
    for(j=0;j<w;++j) for(i=0;i<h;++i) if (a[i][j]!='.') {
        for(k=0;i+k<h && a[i][j]==a[i+k][j];++k);
        if (k>=n)
            for(l=0;l<k;++l) b[i+l][j]='.';
        i+=k-1;
    }

    res=w*h;
    for(j=0;j<w;++j) {
        k=h;
        for(i=h-1;i>=0;--i) if (b[i][j]!='.') a[--k][j]=b[i][j];
        for(i=k-1;i>=0;--i) a[i][j]='.';
        res-=k;
    }
    return res;
}

void swap(char* a, char* b) { char x=*a; *a=*b; *b=x; }

int main(void)
{
    while (~scanf("%d%d%d", &h, &w, &n)) {
        int i, j, yes;
        for(i=0;i<h;++i) scanf("%s", a[i]);

        yes=0;
        memcpy(t, a, sizeof(a));
        for(i=0;i<h;++i) for(j=0;j<w-1;++j) if (a[i][j]!='.' || a[i][j+1]!='.') {
            int p=-1, q=-1;
            swap(&a[i][j], &a[i][j+1]);
            do {
                q=p;
                p=func();
            } while (p!=q);
            if (p==0) { yes=1; goto END; }
            memcpy(a, t, sizeof(a));
        }
END:
        puts(yes ? "YES" : "NO");
    }
    return 0;
}