#include<stdio.h>
#define LEN 15
//Card's struct
typedef struct{
  char c;
  int n;
}Card;

//Stable's struct
typedef struct{
  int i;
  char c[10];
  int n;
}Order;

int main()
{
  int N;
  Card card1[36], card2[36];
  Card copy;
  Order order[LEN];
  char c;
  int mini;
  int i, j, k, n, m;


  //Read N and Cards
  scanf("%d\n", &N);
  for(i=0; i<N; i++)
    {
      scanf("%c%d", &card1[i].c, &card1[i].n);
      //this operation is a step to read ' '.
      scanf("%c", &c);
    }

  //Copy to card_selectiotn and order
  for(i=0; i<N; i++)card2[i]=card1[i];

  //Check this set has same number cards
  for(i=0; i<LEN; i++)order[i].i=0;
  n=0;
  for(i=1; i<=9; i++)
    {
      k=0;
      for(j=0; j<N; j++)if(i==card1[j].n)k++;;
      if(k>1)
	{
	  m=0;
	  order[n].n=i;
	  for(j=0; j<N; j++)
	    {
	      if(i==card1[j].n)
		{
		  order[n].c[m]=card1[j].c;
		  m++;
		}
	    }
	  order[n].i=1;
	  n++;
	}
    }


  //---------------------start----------------------------
  //Begin Bubble Sort
  for(i=0; i<N; i++)
    {
      for(j=1; j<N; j++)
	{
	  if(card1[j].n<card1[j-1].n)
	    {
	      copy=card1[j];
	      card1[j]=card1[j-1];
	      card1[j-1]=copy;
	    }
	}
    }

  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%c%d ", card1[i].c, card1[i].n);
      else printf("%c%d\n", card1[i].c, card1[i].n);
    }

  //Is this Stable?
  m=0;
  for(i=0; i<LEN; i++)
    {
      if(order[i].i!=0)
	{
	  k=0;
	  for(j=0; j<N; j++)
	    {
	      if(card1[j].n==order[i].n)
		{
		  //Not stable
		  if(card1[j].c!=order[i].c[k])
		    {
		      printf("Not stable\n");
		      m=1;
		      break;
		    }
		  else k++;
		}
	    }
	}
      else break;
    }

  //if m=0, it is Stable
  if(m==0)printf("Stable\n");


  //------------------------------------------
  //Selection Sort
  for(i=0; i<N; i++)
    {
      mini=i;
      for(j=i; j<N; j++)
	{
	  if(card2[j].n<card2[mini].n)mini=j;
	}
      copy=card2[i];
      card2[i]=card2[mini];
      card2[mini]=copy;
    }


  //print
  for(i=0; i<N; i++)
    {
      if(i!=N-1)printf("%c%d ", card2[i].c, card2[i].n);
      else printf("%c%d\n", card2[i].c, card2[i].n);
    }

  //Is this Stable?
  m=0;
  for(i=0; i<LEN; i++)
    {
      if(order[i].i==1)
	{
	  k=0;
	  for(j=0; j<N; j++)
	    {
	      if(card2[j].n==order[i].n)
		{
		  //Not stable
		  if(card2[j].c!=order[i].c[k])
		    {
		      printf("Not stable\n");
		      m=1;
		      break;
		    }
		  else k++;
		}
	    }
	}
      else break;
    }

  //if m=0, it is Stable
  if(m==0)printf("Stable\n");

  return 0;
}