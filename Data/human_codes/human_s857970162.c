#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int isEmpty(int);
//int isFull(int);
void push(int x);
int pop();

int S[10000000];
int top;

int main(){
  int a,b;
  int top=0;
  char s[100];
 
  while( scanf("%s", s) != EOF ){
    if ( s[0] == '+' ){
      a=pop();
      b=pop();
      push(a+b);
    }
    else if ( s[0] == '-' ){
      a=pop();
      b=pop();
      push(a-b);
    }
    else if ( s[0] == '*' ){
      a=pop();
      b=pop();
      push(a*b);
    }
    else {
      push(atoi(s));  
    }
  }
  printf("%d\n",pop());
  return 0;
}

/*int isEmpty(int top){
  if(top == 0) return 0;
  else return 1;
}

int isFull(int top){
  if(top >= 100 - 1)return 1;
  else return 0;
  }*/

void push(int x){
  /* if(isFull(top+1)==1)printf("error Overflow\n");
     else*/ top++;
  S[top] = x;
}

int pop(){
  /*if(isEmpty(top)==1)printf("error Underflow\n");
    else*/ top--;
  return S[top+1];
}