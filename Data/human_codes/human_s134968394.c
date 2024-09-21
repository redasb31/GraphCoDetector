#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define REP(i,n) for(i=0;i<n;i++)

int iin() {
    int i;
    scanf("%d", &i);
    return i;
}

long long llin() {
    long long i;
    scanf("%lld", &i);
    return i;
}

double din() {
    double i;
    scanf("%lf", &i);
    return i;
}

char cin() {
    char c;
    scanf("%c", &c);
    return c;
}

void stin(char *s) {
    scanf("%s", s);
}

void iout(int i) {
    printf("%d\n", i);
}

void llout(long long i) {
    printf("%lld\n", i);
}

void dout(double i) {
    printf("%lf\n", i);
}

void cout(char c) {
    printf("%c\n", c);
}

void stout(char *s) {
    printf("%s\n", s);
}

int dfs(int v, int n, int *visited, int table[n][n]) {
    int all_visited = 1, i;

    REP(i,n) {
        if (!visited[i]) {
            all_visited = 0;
            break;
        }
    }

    if (all_visited) {
        return 1;
    }

    int count = 0;

    REP(i,n) {
        if (!table[v][i]) continue;
        if (visited[i]) continue;

        visited[i] = 1;
        count += dfs(i, n, visited, table);
        visited[i] = 0;
    }

    return count;
}

int main() {
    int n = iin();
    char s[n];
    stin(s);
    int k = iin(), i;
    REP(i,n) {
        if (s[k - 1] != s[i]) s[i] = '*';
    }
    stout(s);
    return 0;
}
