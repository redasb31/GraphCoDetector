#include <stdio.h>
int main(){
  int a,b;
  int c=0;
  int i;
  scanf("%d %d",&a,&b);
  for(i=0;i<2;i++){
  	if(a>b){
   	 c+=a;
   	 a--;
 	 }else{
   	 c+=b;
   	 b--;
	 }
  }
  printf("%d\n",c);
  return 0;
}
