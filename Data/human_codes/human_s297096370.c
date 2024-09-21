#include <stdio.h>
 
long long int gcd(long long int a, long long int b);
 
int main(){
    long long int a, b, c, d;
    long long int cntb=0,cnta=0;
 
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
 
    cntb = b;
 
    cntb -= b / c;
    cntb -= b / d;
 
    cntb += b / (c / gcd(c, d)*d);
  
  	cnta = a-1;
  	cnta -= (a-1)/c;
  	cnta -= (a-1)/d;
  
 	cnta += (a-1)/(c/gcd(c,d)*d);
 
    printf("%lld\n", cntb-cnta);
 
    return 0;
 
}
 
long long int gcd(long long int a, long long int b){
  long long int work;
  	if(a>b){
  	  work = a;
  	  a = b;
  	  b = work;
	}
    long long int r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
 
    return b;
}