#include <stdio.h>
int main(){

  long long int N,T,Q,zahyo[100000],muki[100000],ato[100000],daizi[1000],shototu,i,j;

  scanf("%lld %lld %lld",&N,&T,&Q);

  for(i = 0; i < N; i++) scanf("%lld %lld",&zahyo[i],&muki[i]);
  for(i = 0; i < Q; i++) scanf("%lld",&daizi[i]);

  for(i = 0; i < N; i++){

    if(muki[i] == 1){

      ato[i]=zahyo[i]+T;

    } else {

      ato[i]=zahyo[i]-T;

    }

  }

  /*
  for(i = 0; i < Q; i++){                                                                                                                   

    printf("%ld\n",ato[daizi[i]]);                                                                           

  } */

  for(i = 0; i < N-1; i++){

    if(muki[i] == 1 && muki[i+1] == 2){

      shototu=(zahyo[i]+zahyo[i+1])/2;
  
      for(j = 0; j < N; j++){

	if(shototu-zahyo[j] < T && zahyo[j]-shototu < T){

	  ato[j]=shototu;

	}

      }

    }

  }

  for(i = 0; i < Q; i++){

    printf("%lld\n",ato[daizi[i]-1]);

  }

  return 0;

}