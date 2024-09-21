#include <stdio.h>

int M,N;
int Node[303];
int Pnow;
int cnt;
int rem,trgt;

int chk();
void dbg_route(int okng);

int main(){

	int i;
	// 1 <= N <= 100 row
	// 1 <= M <= 2 column
	scanf("%d %d",&N,&M);


	for(i=0;i<303;i++) Node[i]=-1;
	Node[0]=0;
	Pnow=0;
	rem=-1;
	while(Pnow>=0){

		chk();

	}

	printf("%d\n",cnt);

	return 0;
}


int chk(){

	char flg;
	int i;
	
	//set target

	if(Node[Pnow]==(M+1)*(N+1)-1){
		cnt++;
		cnt%=1000000;
//dbg_route(1);
		rem=Node[Pnow];
		Node[Pnow]=-1;
		Pnow--;
		return 0;
	}


	//u-chk
	trgt=Node[Pnow]-(M+1);
	flg=0;
	if(Node[Pnow]<M+1)flg=1;	//edge chk
	for(i=0;i<=Pnow;i++) if(Node[i]==trgt) flg=1;	//been-before chk
	if(trgt<=rem) flg=1;	//back-step & search order chk
	if(!flg){
		Pnow++;
		Node[Pnow]=trgt;
		rem=-1;
		return 1;
	}
	//l-chk
	trgt=Node[Pnow]-1;
	flg=0;
	if(Node[Pnow]%(M+1)==0)flg=1;	//edge chk
	for(i=0;i<=Pnow;i++) if(Node[i]==trgt) flg=1;	//been-before chk
	if(trgt<=rem) flg=1;	//back-step & search order chk
	if(!flg){
		Pnow++;
		Node[Pnow]=trgt;
		rem=-1;
		return 2;
	}
	//r-chk
	trgt=Node[Pnow]+1;
	flg=0;
	if(Node[Pnow]%(M+1)==M)flg=1;	//edge chk
	for(i=0;i<=Pnow;i++) if(Node[i]==trgt) flg=1;	//been-before chk
	if(trgt<=rem) flg=1;	//back-step & search order chk
	if(!flg){
		Pnow++;
		Node[Pnow]=trgt;
		rem=-1;
		return 3;
	}
	//d-chk
	trgt=Node[Pnow]+(M+1);
	flg=0;
	if(Node[Pnow]>(M+1)*N-1)flg=1;	//edge chk
	for(i=0;i<=Pnow;i++) if(Node[i]==trgt) flg=1;	//been-before chk
	if(trgt<=rem) flg=1;	//back-step & search order chk
	if(!flg){
		Pnow++;
		Node[Pnow]=trgt;
		rem=-1;
		return 4;
	}

//dbg_route(0);
	rem=Node[Pnow];
	Node[Pnow]=-1;
	Pnow--;
	return 5;


}

void dbg_route(int okng){
	int i;
	for(i=0;i<=Pnow;i++){
		printf(i==Pnow?"%3d":"%3d-",Node[i]);
	}
	printf("\t%s\n",okng?"OK":"NG");
}