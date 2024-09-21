#include <stdio.h>

int max(int a, int b)
{
   if(a>b) return a;
   else return b;
}

int main(void)
{
   int q1, b, c1, c2, q2;
   int qa;
   int hi, lo, ce;

   while(scanf("%d", &q1)){
      if(q1==0) break;
      scanf("%d %d %d %d", &b, &c1, &c2, &q2);

      qa=0;
      hi=q2;
      lo=1;
      //while(hi>=lo){
         ce=(hi+lo)/2;
	 if(c1*ce+c2*max(q1-ce, 0)<=b){
	    //lo=ce+1;
	    //qa=ce;
            for(qa=q2; qa>=ce; qa--){
               if(c1*qa+c2*max(q1-qa, 0)<=b) break;
            }
	 }
	 else {
	    //if(c1>=c2) hi=ce-1;
	    //else lo=ce+1;
	    if(c1>=c2){
            for(qa=ce-1; qa>0; qa--){
               if(c1*qa+c2*max(q1-qa, 0)<=b) break;
            }}
	    else {
	       qa=max(b/c1, q2);
	    }
	 }
      //}
      if(qa==0) printf("NA\n");
      else printf("%d %d\n", qa, (b-c1*qa)/c2);
   }
   return 0;
}