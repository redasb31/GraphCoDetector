#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#define N 1020
using namespace std;
 
namespace Dinic
{
    class Edge
    {
    public:
        int v;
        int w;
        int i;
 
        Edge(int _v = 0, int _w = 0, int _i = -1) : v(_v), w(_w), i(_i)
        {
            return;
        }
    };
 
    vector<Edge> d;
    vector<int> e[N];
    int l[N], r[N], s;
 
    bool LevelDinic(int s, int t)
    {
        static int q[N];
        int i, j, l, r;
 
        memset(Dinic::l, 0, sizeof(Dinic::l));
        Dinic::l[s] = 1;
 
        l = r = 0;
        for(q[r ++] = s; l < r; l ++)
        {
            s = q[l];
            for(i = 0; i < (signed)e[s].size(); i ++)
            {
                j = e[s][i];
                if(d[j].w && !Dinic::l[d[j].v])
                {
                    Dinic::l[d[j].v] = Dinic::l[s] + 1;
                    q[r ++] = d[j].v;
                }
            }
        }
 
        return Dinic::l[t];
    }
 
    int BlockDinic(int x, int t, int v)
    {
        int i, f;
 
        if(x == t || !v)
            return v;
 
        for(f = 0; r[x] < (signed)e[x].size(); r[x] ++)
        {
            i = e[x][r[x]];
            if(d[i].w && l[d[i].v] == l[x] + 1 && (f = BlockDinic(d[i].v, t, min(v, d[i].w))))
            {
                d[i    ].w -= f;
                d[i ^ 1].w += f;
                break;
            }
        }
 
        return f;
    }
 
    int Dinic(int s, int t)
    {
        int f, o;
 
        for(o = 0; LevelDinic(s, t); )
        {
            memset(r, 0, sizeof(r));
            while((f = BlockDinic(s, t, INT_MAX)))
                o += f;
        }
 
        return o;
    }
 
    void AddEdge(int u, int v, int w, int i)
    {
        // printf("%d->%d : %d\n", u, v, w);
        e[u].push_back(d.size());
        d.push_back(Edge(v, w, i));
        e[v].push_back(d.size());
        d.push_back(Edge(u, 0, -1));
 
        return;
    }
 
    void AddChunk(int u, int v, int l, int r)
    {
        // printf("%d->%d : [%d, %d]\n", u, v, l, r);
        if(l > r)
        {
            printf("-1\n");
 
            exit(0);
        }
        AddEdge(0, v, l, -1);
        AddEdge(u, 1, l, -1);
        AddEdge(u, v, r - l, -1);
        s += l;
 
        return;
    }
}
 
int s[N], t[N];
unsigned long long u[N], v[N];
unsigned long long o[N][N];
 
int main(void)
{
    int n;
    int i, j, k;
 
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &s[i]);
    for(i = 0; i < n; i ++)
        scanf("%d", &t[i]);
    for(i = 0; i < n; i ++)
        scanf("%llu", &u[i]);
    for(i = 0; i < n; i ++)
        scanf("%llu", &v[i]);
 
    for(k = 0; k < 64; k ++)
    {
        Dinic::d.clear();
        for(i = 0; i < N; i ++)
            Dinic::e[i].clear();
        Dinic::s = 0;
 
        for(i = 0; i < n; i ++)
        {
            if(s[i])
                if(u[i] & (1ULL << k))
                    Dinic::AddChunk(2, i + 4, 1, n);
                else
                    ;
            else
                if(u[i] & (1ULL << k))
                    Dinic::AddChunk(2, i + 4, n, n);
                else
                    Dinic::AddChunk(2, i + 4, 0, n - 1);
 
            if(t[i])
                if(v[i] & (1ULL << k))
                    Dinic::AddChunk(i + 4 + n, 3, 1, n);
                else
                    ;
            else
                if(v[i] & (1ULL << k))
                    Dinic::AddChunk(i + 4 + n, 3, n, n);
                else
                    Dinic::AddChunk(i + 4 + n, 3, 0, n - 1);
 
            for(j = 0; j < n; j ++)
                Dinic::AddEdge(i + 4, j + 4 + n, 1, i * n + j);
        }
        Dinic::AddEdge(3, 2, INT_MAX, -1);
 
        if(Dinic::Dinic(0, 1) != Dinic::s)
        {
            printf("-1\n");
 
            return 0;
        }
 
        for(i = 0; i < (signed)Dinic::d.size(); i ++)
            if(Dinic::d[i].i != -1 && !Dinic::d[i].w)
                o[Dinic::d[i].i / n][Dinic::d[i].i % n] |= 1ULL << k;
    }
 
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            printf("%llu%c", o[i][j], " \n"[j == n - 1]);
 
    return 0;
}213