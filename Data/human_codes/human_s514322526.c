/*
 * main.c
 *
 *  Created on: 2020/03/28
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a > b ? b : a)
typedef long long int ll;
typedef unsigned long long int ull;

int sort_inc(const void *a, const void *b) { return (*(int*)a - *(int*)b);}
int sort_dec(const void* a, const void* b) { return (*(int*)b - *(int*)a);}
int sort_dec_ll(const void *a, const void *b) {
    ll da = *(ll*)a, db = *(ll*)b;    int val = 0;
    if(da > db) { val = -1; }
    else if (da == db) { val = 0; }
    else { val = 1; }
    return val;
}
int sort_inc_ll(const void *a, const void *b) {
    ll da = *(ll*)a, db = *(ll*)b;    int val = 0;
    if(da > db) { val = 1; }
    else if (da == db) { val = 0; }
    else { val = -1; }
    return val;
}
int sort_dic(const void *a, const void *b) {
    char *pa = (char *)a;    char *pb = (char *)b;    int i = 0, val = 0, N = 10;
    for (i = 0; i < N; i++) {
    	char da = pa[i], db = pb[i];
    	if (da == db) continue;
  		if (da > db) val = 1; else val = -1;
        break;
    }
    return val;
}

void yesno(int ans) {
	if (ans == 1) {	printf("Yes\n");
	} else {		printf("No\n");	}
	return;
}

void okng(int ans) {
	if (ans == 1) { printf("OK\n");
	} else { 		printf("NG\n");	}
	return;
}

int contest[27] = {0};
int satisfact[366][27] = {0};
int ans[366] = {0};
int t[366] = {0};
int last[27] = {0};
int last_day(int i)
{
	int ret = last[i];
	return ret;
}

int query[100002][2] = {0};
int ans2[100002] = {0};
int main()
{
	int D = 0;
	scanf("%d", &D);
	memset(satisfact, 0, sizeof(satisfact));

	int i = 1, d = 1;
	for (i = 1; i <= 26; i++ ) {
		scanf("%d", &contest[i]);
	}
	for (d = 1; d <= D; d++) {
		for (i = 1; i <= 26; i++ ) {
			scanf("%d", &satisfact[d][i]);
		}
	}
	for (d = 1; d <= D; d++ ) {
		scanf("%d", &t[d]);
	}
	int M = 0, m = 0;
	scanf("%d", &M);
	for (m = 1; m <= M; m++ ) {
		scanf("%d %d", &query[m][0], &query[m][1]);
	}

	// day 1 stisfact = 0
	// contest open .. day d, contest type i statisfact(d,i) increase
	// if contest type not open, test never open last(d,i) = 0.
	for (m = 1; m <= M; m++) {
		int tmp = t[query[m][0]];
		t[query[m][0]] = query[m][1];
		for (d = 1; d <= D; d++) {
			ans[d] = satisfact[d][t[d]] + ans[d - 1];
			for (i = 1; i <= 26; i++ ) {
				if (i != t[d]) {
					ans[d] -= contest[i] * (d - last_day(i));
				}
			}
			last[t[d]] = d;
		}
		for (d = 1; d <= D; d++) {
			//printf("%d\n", ans[d]);
			ans2[m] = ans[d];
		}
		//t[query[m][0]] = tmp;
		memset(last, 0, sizeof(last));
	}
	for (d = 1; d <= M; d++) {
		printf("%d\n", ans2[d]);
	}
	return 0;
}
