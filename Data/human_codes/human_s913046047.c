#include<stdio.h>
int main()
{
  int am, pm, ans, max=0, i, cnt = 0;

  while(1){
    cnt = 0;
    
    for(i=0; i<5; i++){
      scanf("%d%d", &am, &pm);  
      if(am == 0 && pm == 0) break;
      
      ans = am + pm;
      
      if(max < ans){
	max = ans;
	cnt = i;
      }
      
    }

    if(am == 0 && pm == 0) break;

    switch(cnt){

    case 0 :
      printf("A ");
      break;

    case 1 :
      printf("B ");
      break;

    case 2 :
      printf("C ");
      break;

    case 3 :
      printf("D ");
      break;

    case 4 :
      printf("E ");
      break;

    }

    printf("%d\n" , max);
    
  }
  return 0;
  
}