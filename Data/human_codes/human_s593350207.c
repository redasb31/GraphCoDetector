#include <stdio.h>

int min = 1000001;
int A = 0,n,a[21],sum,B,mar,flag,count;
int e = 0;

void make(int x) {
  //printf("start make()\n");
  int i,j,k;

  if(A >= sum) {
    A = 0;
    // printf("Check A = 0\n");
  }

  //printf("%d:x = %d\n",count,x);
  //printf("A = %d\n",A);

   e++;
    B = sum - A;
    if(A - B < 0) mar = -1*(A - B);
    else mar = A - B;
    //printf("%d:A(%d)-B(%d) = %d\n",e,A,B,A-B);
    if(mar < min) min = mar;

    

  
  if(count < n) {
    count++;
    for(i=1;i<n;i++){
    A += a[x];
    make((x+i)%n);
    }
  }

    
    
}



  



int main() {

  int i,j,t,k;

  while(1) {
    min = 1000001;
    scanf("%d",&n);
    if(n == 0) break;

    sum = 0;
    for(i=0;i<n;i++) {

      scanf("%d",&a[i]);
      sum += a[i];
    }

    for(i=0;i<n;i++)
      for(j=i;j<n;j++){

	if(a[i] > a[j]){
	  t = a[i];
	  a[i] = a[j];
	  a[j] = t;
	}
      }

    
    for(i=0;i<n;i++) {
      count = 0;
      A = 0;
      make(i);
    }
    printf("%d\n",min);
  }

  return 0;

}