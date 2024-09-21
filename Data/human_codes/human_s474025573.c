#define DEBUG_MODE 0

#include <stdio.h>
#include <stdlib.h>

#define Q_MAX 4
#define PIECE_SIZE 4
#define W_MAX 10
#define H_MAX 60

/* Queue */

int Q[Q_MAX], sp, rp;

void Qinit(){ sp=0, rp=0; }
void Qstore(int N){ Q[sp++%Q_MAX]=N; }
void Qstore2(int N, int M){ Q[sp++%Q_MAX]=N; Q[sp++%Q_MAX]=M; }
int Qretrive(){ return Q[rp++%Q_MAX]; }
int Qempty(){ return sp==rp; }

/* piece */

struct piece{
	int id;
	double gc;	/* gravity center */
	struct piece* firstChild;
	struct piece* nextBrother;
};

struct piece *piece[W_MAX*H_MAX/PIECE_SIZE]; int pp;	/* pieces dictionary */

void new_piece(){
	int i; struct piece *res=malloc(sizeof(struct piece));
	piece[++pp]=res;
	res->id=pp, res->gc=-1, res->firstChild=NULL, res->nextBrother=NULL;
}

void initPieces(){
	int i;
	for(i=0; i<=pp; i++) if(piece[i]!=NULL) free(piece[i]), piece[i]=NULL;
	pp=-1;
}

void affiliate(int childId, int parentId){	/* let A be B's child */
	struct piece *t; t=piece[parentId];
	
	if(t->firstChild==NULL){
	
	t->firstChild=piece[childId];
	
	}else{
	
	t=t->firstChild;
	while(t->nextBrother!=NULL) t=t->nextBrother;
	t->nextBrother=piece[childId];
	
	}
}

int has(int childId, int parentId){	/* if B has A as a child */
	struct piece *t; t=piece[parentId]->firstChild;
	while(t!=NULL){
		if(t==piece[childId]) return 1;
		t=t->nextBrother;
	}
	return 0;
}

/* main */

int map[W_MAX][H_MAX];
int input[W_MAX][H_MAX], W, H;

void tokenizePiece(int x, int y){	/* analyze a piece */
	double sum=0; int id; new_piece();
	id=input[x][y], Qinit(), input[x][y]=-1; Qstore2(x,y);
	while(!Qempty()){
		x=Qretrive(); y=Qretrive();
		map[x][y]=pp, sum+=x+0.5;
		
		if(x+1<W && input[x+1][y]==id) input[x+1][y]=-1, Qstore2(x+1,y);
		if(y+1<H && input[x][y+1]==id) input[x][y+1]=-1, Qstore2(x,y+1);
		if(x>0 && input[x-1][y]==id) input[x-1][y]=-1, Qstore2(x-1,y);
		if(y>0 && input[x][y-1]==id) input[x][y-1]=-1, Qstore2(x,y-1);
	}
	piece[pp]->gc=(double)sum/PIECE_SIZE;
}

int L(int id){	/* the XL value of the piece */
	int x,y,l=W;
	for(y=0; y<H; y++)
		for(x=0; x<W; x++)
			if(map[x][y]==id && (y+1==H || (map[x][y+1]!=-1 && map[x][y+1]!=id) ) && x<l) l=x;
	return l;
}

int R(int id){	/* the XR value of the piece */
	int x,y,r=0;
	for(y=0; y<H; y++)
		for(x=0; x<W; x++)
			if(map[x][y]==id && (y+1==H || (map[x][y+1]!=-1 && map[x][y+1]!=id) ) && x>r) r=x;
	return r+1;
}

double GC(int id){	/* GravityCenter of the subtree */
	double sum=0; int i=0; Qinit();
	
	sum+=piece[id]->gc, i++;
	if(piece[id]->firstChild!=NULL) Qstore(piece[id]->firstChild->id);
	
	while(!Qempty()){
		id=Qretrive();
		sum+=piece[id]->gc, i++;
		if(piece[id]->firstChild!=NULL) Qstore(piece[id]->firstChild->id);
		if(piece[id]->nextBrother!=NULL) Qstore(piece[id]->nextBrother->id);
	}
	return sum/i;
}

int main(void){
	int x, y, i; char c; struct piece *t;
	
	while(scanf("%d %d\n",&W,&H), W!=0){
	
		/* initialize */
		initPieces();
		for(x=0; x<=W; x++) for(y=0; y<=H; y++) map[x][y]=-1;
	
		/* get input */
		for(y=0; y<H; y++){
			for(x=0; x<W; x++){
				getitem:
			
				scanf("%c",&c);
				
				if(c=='\n') goto getitem;
				else if(c=='.') input[x][y]=-1;
				else input[x][y]=c-'0';
			}
		}
		
		/* tokenize */
		for(y=0; y<H; y++)
			for(x=0; x<W; x++)
				if(input[x][y]!=-1) tokenizePiece(x,y);

		/* parse relations */
		for(y=0; y<H-1; y++)
			for(x=0; x<W; x++)
				if(map[x][y]!=-1 && map[x][y+1]!=-1 && map[x][y]!=map[x][y+1])
					if(!has(map[x][y],map[x][y+1]))
						affiliate(map[x][y],map[x][y+1]);
		
		/* judge */
		for(i=0; i<=pp; i++)
			if(L(i)>=GC(i) || GC(i)>=R(i)){ printf("UNSTABLE\n"); break; }
		if(i>pp) printf("STABLE\n");

#if DEBUG_MODE

		printf("\n");

		/* check(map) */
		printf("map:\n");
		for(y=0; y<H; y++){
			for(x=0; x<W; x++){
				if(map[x][y]!=-1) printf("%d",map[x][y]);
				printf("\t");
			}
			printf("\n");
		}
		printf("\n");	
						
		/* check(relations) */
		printf("relation:\n");
		for(i=0; i<=pp; i++){
			printf("%d has ",i);
			
			t=piece[i]->firstChild;
			while(t!=NULL) printf("%d ",t->id), t=t->nextBrother;
			printf("\n");
		}
		printf("\n");
		
		/* check(judge) */
		printf("gravity center:\n");
		for(i=0; i<=pp; i++){
			printf("%d | L:%d GC:%lf R:%d\n",i,L(i),GC(i),R(i));
		}
		printf("\n");
		
		/* partition */
		printf("************\n\n");
		
#endif
	}
}