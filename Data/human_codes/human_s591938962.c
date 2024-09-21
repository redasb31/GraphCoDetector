#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 110
#define Initial 0
#define Medium 1
#define End 2
#define Gard -1

int Graph[N][N];
int Length[N]; 
int Storage[N]; 
int Fin[N];
int start=0;
int finish=0;
int loop;

void EnQueue(int );
int DeQueue();

int main(){
  int i,j;
  int vertex,adja;
  int adnum;
  int locate=0;
  
  scanf("%d",&loop);
  for(i=1;i<loop+1;i++){
    scanf("%d %d",&vertex,&adja);

    for(j=1;j<adja+1;j++){
      scanf("%d",&adnum);

      if(adnum!=0){
	Graph[vertex][adnum]=1;
      }

      else{
	Graph[vertex][adnum]=0;
      }
      
    }
  }

  for(i=1;i<loop+1;i++){
    Fin[i]=Initial;
    Length[i]=Gard;
  }

  Fin[Medium]=Medium;
  Length[Medium]=0;

  EnQueue(Medium);

  while(start!=finish){
    locate=DeQueue();
    
    for(i=1;i<loop+1;i++){

      if(Graph[locate][i]==Initial){
	continue;
      }

      else if(Length[i]!=Gard){
	continue;
      }
      
 
      else if(Fin[i]==Initial){
	Fin[i]=Medium;
	Length[i]=Length[locate]+1;
	EnQueue(i);
      }
    }
    

    Fin[locate]=End;
  }
  
  for(i=0;i<loop;i++){
    printf("%d %d\n",i+1,Length[i+1]);
  }

  return 0;
}

void EnQueue(int queue){

  Storage[finish]=queue;

  if(finish+1==loop){
    finish=0;
  }

  finish++;
}

int DeQueue(){
  int queue;

  queue=Storage[start];

  if(start+1==loop){
    start=0;
  }

  start++;

  return queue;
}

