#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i,stk,x[3];
char tex[1000000],code[1000000];
char encode[64][6]={
"11010",
"",
"",
"",
"",
"",
"",
"11110",
"",
"",
"",
"",
"11100",
"11101",
"11011",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"",
"11111",
"",
"00000",
"00001",
"00010",
"00011",
"00100",
"00101",
"00110",
"00111",
"01000",
"01001",
"01010",
"01011",
"01100",
"01101",
"01110",
"01111",
"10000",
"10001",
"10010",
"10011",
"10100",
"10101",
"10110",
"10111",
"11000",
"11001",
"",
"",
"",
"",
""}
,decode[100000000];

int main(){
	decode[212]=' ';
	decode[111111]='\'';
	decode[111122]=',';
	decode[21121112]='-';
	decode[121112]='.';
	decode[111112]='?';
	decode[211212]='A';
	decode[21122121]='B';
	decode[1212]='C';
	decode[1112]='D';
	decode[221]='E';
	decode[12112]='F';
	decode[21122122]='G';
	decode[121111]='H';
	decode[1222]='I';
	decode[21122111]='J';
	decode[1221]='K';
	decode[11211]='L';
	decode[21122112]='M';
	decode[21122221]='N';
	decode[11212]='O';
	decode[222]='P';
	decode[21122222]='Q';
	decode[2111]='R';
	decode[11221]='S';
	decode[11222]='T';
	decode[21122211]='U';
	decode[21122212]='V';
	decode[111121]='W';
	decode[21121121]='X';
	decode[21121122]='Y';
	decode[21121111]='Z';

	while(fgets(tex,900000,stdin)!=NULL){
		strcpy(code,"");
		for(i=0;i<strlen(tex);i++){
			strcat(code,encode[tex[i]-' ']);
		}
		stk=0;
		for(i=0;i<strlen(code);i++){
			stk=stk*10+code[i]-'0'+1;
			if(decode[stk]>0){
				printf("%c",decode[stk]);
				stk=0;
			}
		}
		printf("%\n");
	}
	return 0;
}