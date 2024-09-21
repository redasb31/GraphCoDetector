#include <stdio.h>
#include <string.h>

int main(void){
  char str[100];
  int counter = 0;
  int flag[8] = {0,0,0,0,0,0,0,0};
  int is_end = 0;
  scanf("%s",str);

  for(int i = 0;i<strlen(str);i++){
    switch(counter){
      case 0:
        if(str[i] == 'k'){
          counter++;
        }else{
          flag[0] = 1;
        }
        break;
      case 1:
        if(str[i] == 'e'){
          counter++;
        }else{
          flag[1] = 1;
        }
        break;
      case 2:
        if(str[i] == 'y'){
          counter++;
        }else{
          flag[2] = 1;
        }
        break;
      case 3:
        if(str[i] == 'e'){
          counter++;
        }else{
          flag[3] = 1;
        }
        break;
      case 4:
        if(str[i] == 'n'){
          counter++;
        }else{
          flag[4] = 1;
        }
        break;
      case 5:
        if(str[i] == 'c'){
          counter++;
        }else{
          flag[5] = 1;
        }
        break;
      case 6:
        if(str[i] == 'e'){
          counter++;
          is_end = 1;
        }else{
          flag[6] = 1;
        }
        break;
      case 7:
        flag[7] = 1;
        break;
    }
  }

  if(is_end == 1){
    int count = 0;
    for(int i = 0;i<8;i++){
      if(flag[i]){
        count++;
      }
    }
    if(count == 0 || count == 1){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}