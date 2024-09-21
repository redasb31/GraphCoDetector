#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true  (!false)

#define NMAX 100000
#define MMAX 200000

struct graph_t {
    int node;              // 両端のノード番号
    int cord;              // コードの番号
    struct graph_t *next;  // 次のデータへのポインタ
};

struct bomb_t {
    int A;              // 爆弾の番号
    int B;              // 爆弾の初期状態
    int D;              // 爆弾の初期状態の差分
    struct graph_t *G;  // グラフ情報
    int used;           // DFSで使用済み判定用
};

int N;                   // 爆弾数
int M;                   // コードの数
struct bomb_t AB[NMAX];  // 爆弾情報
int ans[NMAX];
int ansNum = 0;
struct graph_t stock[MMAX*2];
int stockNum = 0;

/***********************************************************
    デバッグ用出力
***********************************************************/
void dump( void )
{
    int i;
    struct graph_t *p;

    printf( "\n***** DUMP\n", M );
    for( i=0; i<N; i++ ) {
        printf( "No.%d %d %d", i, AB[i].A, AB[i].D );
        p = AB[i].G;
        while( p ) {
            printf( " (node%d cord%d)", p->node, p->cord );
            p = p->next;
        }
        printf( "\n" );
    }
    p = AB[i].G;
    printf( "No.%d", N );
    while( p ) {
        printf( " (node%d cord%d)", p->node, p->cord );
        p = p->next;
    }
    printf( "\n" );
}

/***********************************************************
    ソート用比較関数
***********************************************************/
int cmpfunc( const void *a, const void *b )
{
    return( ((struct bomb_t *)a)->A - ((struct bomb_t *)b)->A );
}

int ansCmpFunc( const void *a, const void *b )
{
    return( *((int *)a) - *((int *)b) );
}

/***********************************************************
    グラフの辺を追加
***********************************************************/
void appendNode( struct bomb_t *b, int node, int cord )
{
    struct graph_t *p = b->G;
    struct graph_t *n = &stock[stockNum++];

    n->node = node;
    n->cord = cord;
    n->next = NULL;

    if( b->G == NULL ) {
        b->G = n;
        return;
    }

    n->next = b->G;
    b->G = n;
}

/***********************************************************
    指定された要素以上の値が現れる最初の位置
***********************************************************/
int searchL( int n )
{
    int l = 0;
    int r = N-1;
    int c;

    if( n <= AB[0].A ) return( 0 );
    if( n > AB[N-1].A ) return( N );

    while( r-l > 1 ) {
        c = (l+r) /2;
        if( AB[c].A >= n ) r = c;
        else              l = c;
    }

    return( r );
}

/***********************************************************
    指定された要素より大きい値が現れる最初の位置
***********************************************************/
int searchR( int n )
{
    int l = 0;
    int r = N-1;
    int c;

    if( n < AB[0].A ) return( 0 );
    if( n >= AB[N-1].A ) return( N );

    while( r-l > 1 ) {
        c = (l+r) /2;
        if( AB[c].A > n ) r = c;
        else              l = c;
    }

    return( r );
}

/***********************************************************
    深さ優先探索
***********************************************************/
int dfs( int node, int state )
{
    AB[node].used = true;

    int ret = AB[node].D;
    struct graph_t *p = AB[node].G;

    while( p ) {
        if( ! AB[p->node].used ) ret ^= dfs( p->node, p->cord );
        p = p->next;
    }

    if( ret ) {
        if( state == -1 ) {
            puts( "-1" );
            exit( 0 );
        }

        ans[ansNum] = state;
        ansNum ++;
    }

    return( ret );
}

/***********************************************************
    main
***********************************************************/
int main( int argc, char *argv[] )
{
    int i;
    int L, R;
    struct graph_t *p;

    // NとMを読み込む
    if( scanf( "%d%d", &N, &M ) != 2 ) {
        printf( "N M read error!\n" );
        exit( -1 );
    }

    // 爆弾情報を読み込む
    for( i=0; i<N; i++ ) {
        if( scanf( "%d%d", &AB[i].A, &AB[i].B ) != 2 ) {
            printf( "AB[%d] read error!\n", i );
            exit( -1 );
        }

        if( AB[i].B == 1 ) AB[i].B = true;
        else               AB[i].B = false;
    }

    // 爆弾の座標の小さい順に並び変え
    qsort( AB, N, sizeof(struct bomb_t), cmpfunc );

    // 爆弾のON/OFFの差分を計算
    AB[0].D = AB[0].B;
    for( i=1; i<N+1; i++ ) AB[i].D = AB[i].B ^ AB[i-1].B;

    // コード情報を読み込みグラフのノードとして保存
    for( i=0; i<M; i++ ) {
        if( scanf( "%d%d", &L, &R ) != 2 ) {
            printf( "AB[%d] read error!\n", i );
            exit( -1 );
        }

        L = searchL( L );
        R = searchR( R );
        if( L == R ) continue;

        appendNode( &AB[L], R, i+1 );
        appendNode( &AB[R], L, i+1 );
    }

    for( i=0; i<N; i++ ) {
        if( ! AB[i].used ) {
            dfs( i, -1 );
        }
    }

    qsort( ans, ansNum, sizeof( int ), ansCmpFunc );

    printf( "%d\n", ansNum );
    for( i=0; i<ansNum; i++ ) printf( "%d ", ans[i] );
    printf( "\n" );
}
