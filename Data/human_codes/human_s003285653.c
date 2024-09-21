#include<stdio.h>

char S[15]

int j = 0;
int g = 0;

for(int i= 0; i<15; i++){
scanf("%s", &S[i]);
}
for(int k = 0; k <15; k++){
  if(S[k] == x){
   j++;
   }
  if(j >= 8){
     printf("NO\n");
  }
  printf("YES\n");
  
  return 0;
}
