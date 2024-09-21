#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elm {
    struct elm *next, *prev;
    int data;
} elm_t;

typedef struct {
    elm_t *front, *back;
} list_t;

void push_back(list_t *list, int data) {
    elm_t *e = malloc(sizeof(elm_t));
    elm_t *f = list->back->prev;
    e->next = f->next;
    e->prev = f;
    e->data = data;
    f->next = e;
    list->back->prev = e;
}

list_t *mklist() {
    list_t *l = malloc(sizeof(list_t));
    l->front = malloc(sizeof(elm_t));
    l->back = malloc(sizeof(elm_t));
    l->front->next = l->back;
    l->back->prev = l->front;
    return l;
}

char buf[100000 * 32];
int a[200000][2];

int cmp(const void *const key, const void *const memb) {
    return *(const int *) key - *(const int *) memb;
}

int main() {
    int n = 0, p = 0;
    long long r = 1;
    //FILE *f = fopen("in.txt","r");
    //size_t s = fread(buf, sizeof(*buf), 100000 * 32, f);
    size_t s = fread(buf, sizeof(*buf), 100000 * 32, stdin);
    int c = -1;
    for (size_t i = 0; i < s; i++) {
        if (buf[i] >= '0' && buf[i] <= '9') {
            int k = (int) strtol(buf + i, NULL, 10);
            if (c < 0) n = k;
            else {
                a[c][0] = k;
                a[c][1] = (c / n) * 2 - 1;
            }
            c++;
            while (buf[i] >= '0' && buf[i] <= '9')i++;
        }
    }
    qsort(a, n * 2, sizeof(int) * 2, cmp);
    for (int i = 0; i < n * 2; i++) {
        if (p * a[i][1] < 0) r = (r * abs(p)) % 1000000007;
        p += a[i][1];
    }
    printf("%lld\n", r);
}
