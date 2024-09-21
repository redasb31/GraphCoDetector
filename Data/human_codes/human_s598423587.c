#include <stdio.h>
#include <math.h>

#define EPS 1e-4

typedef struct {
    double x, y;
} point_t;

double deg2rad(int deg) {
    return deg * M_PI / 180.0;
}

double dot(double a, double b, double c, double d) {
    return a * c + b * d;
}


int main(void) {
    int N, i, j, cnt1, cnt2, h;
    point_t p[100], vec[100], *pa, *pb, *v, *va, *vb;
    double len[100], *l, d, cos1;
    double t1, t2, s1, s2, s, ss;

    t1 = deg2rad(36);
    t2 = deg2rad(72);
    s1 = sin(t1);
    s2 = sin(t2);
    cos1 = cos(t1);
    while (scanf("%d", &N) == 1) {
        for (i = 0; i < N; i++) {
            scanf("%lf%lf", &(p[i].x), &(p[i].y));
        }

        cnt1 = cnt2 = 0;
        // edge
        for (i = 0; i < N; i++) {
            h = (i-1+N)%N;
            pa = &p[h];
            pb = &p[i];
            v = &vec[h];
            l = &len[h];
            v->x = pb->x - pa->x;
            v->y = pb->y - pa->y;
            *l = hypot(v->x, v->y);
            if (fmod(*l, 1.00000) > EPS) goto illegal;
        }
        // angle
        for (i = 0; i < N; i++) {
            h = (i-1+N)%N;
            va = &vec[h];
            vb = &vec[i];
            /*
            printf(": %.4lf %.4lf %.4lf | %.4lf %.4lf %.4lf\n",
                   va->x, va->y, len[h], vb->x, vb->y, len[i]);
            printf(": %.6lf %.6lf| %.6lf\n",
                acos(dot(-va->x, -va->y, vb->x, vb->y)/(len[h]*len[i])),
                t1,
                fabs(fmod(acos(dot(-va->x, -va->y, vb->x, vb->y)/(len[h]*len[i])) + EPS, t1) - EPS)
                );*/
            if (fabs(fmod(
                acos(dot(-va->x, -va->y, vb->x, vb->y)/(len[h]*len[i])) + EPS,
                     t1) - EPS)
                > EPS) goto illegal;
        }

        // area
        for (i = 0, s = 0; i < N; i++) {
            h = (i + N -1) % N;
            pa = &p[h];
            pb = &p[i];
            s += (pa->x - pb->x) * (pa->y + pb->y);
        }
        s *= .5;
        for (i = 0, cnt2 = 0, ss = s;
             ss > EPS &&
             fabs(fmod(ss/s1, 1.00000)) > EPS;
             cnt2++, ss = s-s2*cnt2) {
        }
        if (ss < 0 || fabs(fmod(ss/s1, 1.00000)) > EPS) goto illegal;
        cnt1 = ss / s1;
        
        printf("%d %d\n", cnt1, cnt2);
        continue;

        illegal:
        printf("-1 -1\n");
    }
    return 0;
}