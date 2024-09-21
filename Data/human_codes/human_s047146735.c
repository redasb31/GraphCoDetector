/*
	??????????????´??¨??????
	????±??????????1W142208-3
	????????\???2015/10/6
	?????????
		???????????????????????¨??????????????????????????????
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 101	//??????????????§????????°???

//????????¨????????????????????????????????????????????????????????¨??§??????????????¢?????§???????§??????????
typedef struct CHAR Char;
struct CHAR{
	char c;	//?????????
	Char *prev;	//????????????????????????next???????????´??????NULL???
	Char *next;	//?¬??????????????????????prev???????????´??????NULL???
};

int Main();	//???????????????
int SetCHAR(Char *ch, char _c, Char *_prev, Char *_next);	//Char?§???????????????????????????¢??°???
int Output(Char *begin, Char *cursor);	//??????????????????????????????begin?????????????????????next????????????????????????cursor???????????????????????????????????¢?????¬???????????????

int main(int argc, char *argv[]){
	int n = 0, i = 0;	//????????????????????°???
	if( scanf("%d", &n) != 1 ){ return -1; }
	for( i = 0; i < n; i++ ){ Main(); }
	return 0;
}

int Main(){
	Char *begin, *end, *x, *t;	//???????????????('\0'?????????)???????????????(?????????????´??????????)?????°?????¨????????????????????°???????????????????????????????????????????????????
	//begin??¨end???????????????
	begin = (Char*)malloc(sizeof(Char));
	end = (Char*)malloc(sizeof(Char));
	SetCHAR(begin, '\0', NULL, end);
	SetCHAR(end, '\0', begin, NULL);
	int numCom = 0;	//?????????????????°???
	char ch = '\0';	//?????????????????\???????????\????????????????´???¨???
	int i = 0, j = 0;
	//????????????????????\??????
	x = begin;
	getchar();	//??´????????\?????§????????????????????¨??????
	//???????????????1?????????????????????
	while( scanf("%c", &ch) == 1 && ch != '\n' ){
		t = (Char*)malloc(sizeof(Char));
		t->c = ch;
		x->next = t;
		t->prev = x;
		x = x->next;
	}
	x->next = end;
	end->prev = x;
	x = begin->next;	//x?????????????????????????????????
	if( scanf("%d", &numCom) != 1 ){ return -1; }	//??????????????°?????\??????
	for( i = 0; i < numCom; i++ ){
		char mCom[10], aCom[SIZE];	//1?????????????????????(forward, backward, insert, delete)???2?????????????????????(char, word, any-text)???
		if( scanf("%s %[^\n]", mCom, aCom) != 2 ){ return -1; }	//aCom????????????????????????????????????????????????
		//1???????????????????????§?????¶?????????????????????2???????????????????????????????????????????????????????????????
		if( strcmp(mCom, "forward") == 0 ){
			if( strcmp(aCom, "char") == 0 ){
				//x???end??§???????????????x????¬?????????????????????????????????????
				if( x != end ){ x = x->next; }
			}else if( strcmp(aCom, "word") == 0 ){
				//????????????????????????????????????????????°????????????????????????????????????????????????
				if( x->c == ' ' ){ for( ; x->next != NULL && x->c == ' '; x = x->next ); }
				//???????????°????????????????????????????¬??????\??????????????§????????????????§????????????????
				for( ; x->next != NULL && x->c != ' '; x = x->next );
			}
		}else if( strcmp(mCom, "backward") == 0 ){
			if( strcmp(aCom, "char") == 0 ){
				//x???1????????¨begin?????¢?????¬???????????´????????´?????????x????????????????????§???????????§???????????§????????´?????????1??????????????????x???????????????????????????
				if( x->prev != begin ){ x = x->prev; }
			}else if( strcmp(aCom, "word") == 0 ){
				//????????????????????????????????????????????°?????????????????????????????????????????????
				if( x->prev->c == ' ' ){ for( ; x->prev != begin && x->prev->c == ' '; x = x->prev ); }
				//???????????°???????????????????????????????????\??????????????§????????????????§????????????????
				for( ; x->prev != begin && x->prev->c != ' '; x = x->prev );
			}
		}else if( strcmp(mCom, "insert") == 0 ){
			//?????¨?????????????????????????¨???????????????????
			Char *nx;
			nx = x;
			x = x->prev;
			//?????????????????????????????§?????????????????????????????§???????¶??????????
			for( j = 1; aCom[j] != '\"'; j++ ){
				t = (Char*)malloc(sizeof(Char));
				t->c = aCom[j];
				x->next = t;
				t->prev = x;
				x = x->next;
			}
			//??????????????£??????
			nx->prev = x;
			x->next = nx;
			x = x->next;
		}else if( strcmp(mCom, "delete") == 0 ){
			if( strcmp(aCom, "char") == 0 ){
				if( x->next != end && x != end ){
					//x->prev??¨x->next????????????????????????x????§£????????????
					Char *nx;
					nx = x->next;	//2?????????????????????????????????
					x = x->prev;
					free(x->next);	//??????????????????????§£????????????
					//??????????????£??????
					x->next = nx;
					nx->prev = x;
					x = x->next;
				}
			}else if( strcmp(aCom, "word") == 0 ){
				//1???????????????(begin?????????)????¨??????????????????????????????????????????????????????????????????¨??£????????????
				//??????????????????????????????????????¨???????????????????????????????????´???????????????????????????
				Char *temp;
				for( temp = x; temp != end; temp = temp->next ){
					if( temp->c != ' ' ){ break; }
				}
				if( temp != end ){
					Char *bx;
					bx = x->prev;
					if( x->next != end && x != end ){
						if( x->c == ' ' ){
							//????????????????????????????????????
							for( ; x != end && x->c == ' '; free(x->prev) ){ x = x->next; }
							//??????????????£??????
							bx->next = x;
							x->prev = bx;
						}
						//?????????????????????????????§??????????????????????????????
						for( ; x != end && x->c != ' '; free(x->prev) ){ x = x->next; }
						//??????????????£??????
						bx->next = x;
						x->prev = bx;
					}
				}
			}
		}
	}
	Output(begin, x);	//x????????¨???????????????????????????
	for( x = begin; x != end; x = x->next ){
		free(x->prev);
	}
	free(x);
	return 0;
}

int SetCHAR(Char *ch, char _c, Char *_prev, Char *_next){
	ch->c = _c;
	ch->next = _next;
	ch->prev = _prev;
	return 0;
}

int Output(Char *begin, Char *cursor){
	Char *x;
	for( x = begin->next; x != NULL; x = x->next ){
		if( x == cursor ){ printf("^"); }	//???????????????????????¨?????´????????????'^'???????????????(?????????????????????'^'???????±????????????????)???
		if( x->next != NULL ){ printf("%c", x->c); }
	}
	printf("\n");
	return 0;

}