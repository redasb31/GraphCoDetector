#include <stdio.h>
int koyaku(int a,int b){
  if(b==0) return a;
  else return koyaku(b,a%b);
}
main(){
  int i,j,c;
  long long L;
  while(1){
    c=0;
    scanf("%lld",&L);
    if(L==0) break;

 for(i=1;i<=L;i++){
   if(L%i!=0) continue;
      for(j=i;j<=L;j++){
	if(L%j!=0) continue;
	if((long long)i*j/koyaku(i,j)==L) c++;
      }
    }

    printf("%d\n",c);
  }
  return 0;
}