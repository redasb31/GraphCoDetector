#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **dmatrix(int x,int y);	/*x行y列の配列を確保する*/
void free_dmatrix(int **a,int x);/*x行の配列を解放する*/

int main(void){
	int D;/*コンテストの日数通常365日*/
	int c[26];/*減点項*/
	int **s;/*加点項*/
	int lday[26]={0};/*最後にした日を記録（最初は0）*/
	int *t;/*スコア計算用*/
	int score;/*スコア*/
	int i,j;
	char str[1000000];
 
	/*入力*/
	fgets(str, sizeof(str), stdin);
	D=atoi(strtok(str," "));

	fgets(str,sizeof(str), stdin);
	c[0]=atoi(strtok(str," "));
	for(i=1;i<26;i++){
		c[i]=atoi(strtok(NULL," "));
	}
	s=dmatrix(D,26);
	for(i=0;i<D;i++){
		fgets(str,sizeof(str), stdin);
		s[i][0]=atoi(strtok(str," "));
		for(j=1;j<26;j++){
			s[i][j]=atoi(strtok(NULL," "));
		}
	}
	/*入力*/

	/*入力（出力を読み込む）*/
	t=(int*)calloc(D,sizeof(int));
	for(i=0;i<D;i++){
		fgets(str,sizeof(str), stdin);
		t[i]=atoi(strtok(str," "));
	}
	/*入力（出力を読み込む）*/

	/*スコア計算、出力*/
	score=0;
	for(i=0;i<D;i++){/*tに関しては例題の出力が1からだから補正*/
		score+=s[i][t[i]-1];
		lday[t[i]-1]=i+1;/*例題の出力が1からだから補正*/
		for(j=0;j<26;j++){
			score-=c[j]*(i+1-lday[j]);
		}
		printf("%d\n",score);
	}
	/*スコア計算、出力*/


	free(t);
	free_dmatrix(s,D);

	return 0;
}

int **dmatrix(int x,int y)			/*x行y列の配列を確保する.*/
{
	int i;
	int **a;
	if ( ( a = (int**)calloc(x,sizeof(int*)) ) == NULL){
		exit(1);
	}
	for(i=0;i<x;i++) a[i]=(int*)calloc(y,sizeof(int));
	return (a);
}

void free_dmatrix(int **a,int x)/*x行の配列を解放する.*/
{
	int i;
	for (i=0;i<x;i++) free((void*)(a[i]));	
	free((void*)(a)); 
}