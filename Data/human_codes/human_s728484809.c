#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint;
#define PARENT(i) ((i)>>1)
#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)+1)
#define SWAP(x,y) (x^=y^=x^=y)
#define gc getchar
#define Mmax 300000
int s[Mmax],t[Mmax],c[Mmax],q[Mmax],qnum=0;

int scan(int*N)
{
	int c,n=0;
	for(c=gc();'0'<=c&&c<='9';c=gc())
	    n=(n*10)+(c&0xf);
	if(N!=NULL)*N=n;
	return n;
}

void func(int i)
{
	int l=LEFT(i),r=RIGHT(i),m=i;
	if(l<qnum&&q[l]>q[m])m=l;
	if(r<qnum&&q[r]>q[m])m=r;
	if(m!=i){SWAP(q[m],q[i]);func(m);}
}

uint pop(void)
{
	uint c=(uint)q[0];
	q[0]=q[--qnum];
	func(0);
	return c;
}

void push(int c)
{
	int i,p;
	q[i=qnum++]=c;
	for(i&&1;q[p=PARENT(i)]<q[i];i=p)
	    SWAP(q[p],q[i]);
}

int main()
{
	int N,M,T=0,i=0;
	uint a=0;
	scan(&N);
	while(i<N){s[i]=scan(&M),t[i++]=T;while(M--)c[T++]=scan(NULL);}
	for(i=N-1;i>=0;i--){M=s[i],T=t[i];while(M--)push(c[T++]);a+=pop();}
	printf("%u\n",a);
}

/*
#define DEBUG
#ifndef DEBUG
#define DEBUG if(0)
#endif



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define gc getchar
int scan(int*N)
{
	int c,n=0;
	for(c=gc();'0'<=c&&c<='9';c=gc())
	    n=(n*10)+(c&0xf);
	if(N!=NULL)*N=n;
	return n;
}

typedef struct
{
    int p; //得点
    int d; //深さ
	int w; //ノードの重さ
}S_dungeon;

typedef struct
{
    int s; //隣接部屋1
    int t; //隣接部屋2
}S_path;

#define N_MAX 100000
S_dungeon room[N_MAX];
S_path adjacency[N_MAX];

int comp( const void * a, const void * b )
{
	if( ((S_path *)a)->s == ((S_path *)b)->s ){
		return ((S_path *)a)->t - ((S_path *)b)->t;
	}
	return ((S_path *)a)->s > ((S_path *)b)->s;
}

void score_parent_node(int i)
{
	int n = i+1;
}

int cal_score(void)
{
	int i;
	for( i = 0; i < N; i++)
	{
		if( room[i].w > 2 ){
			score_parent_node(i);
		}
	}
	return 0;
}

int main()
{
	int i,N;
	
	scanf("%d", &N );
	for( i = 0; i < N; i++ ){
	    scanf("%d", &room[i].p );
	}
	rewind(stdin);
	for( i = 0; i < N-1; i++ ){
		room[ scan( &adjacency[i].s )-1 ].w++;
		room[ scan( &adjacency[i].t )-1 ].w++;
	}
	
	qsort( adjacency, N-1, sizeof(adjacency[0]), comp );
	
	
DEBUG{
	for( i = 0; i < N; i++ ){
		printf("[%d] p = %d, w = %d, s = %d, t = %d\n", i, room[i].p, room[i].w, adjacency[i].s, adjacency[i].t );
	}
}
	
	printf("%d", cal_score() );
	
	return 0;
}
*/

/* test data (copy and paset for input)
7
6
1
-1
4
3
3
1
1 2
2 3
3 4
3 5
5 6
5 7
*/


