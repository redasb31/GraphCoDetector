#include<stdio.h>
int main(){
  int n,i,j,r[400],t,p,c;
  unsigned long long int a,id[1001];
  while(scanf("%d",&n),n){
    int u[100000]={0};
    int uc[1000]={0};
    for(i=c=0;i<n;i++){
      r[i]=i;
      scanf("%lld %d %lld %d",&id[i],&u[i],&a,&p);
      id[i]+=((10-a)*1000000+p)*10000;//printf("%lld\n",id[i]);
      for(j=i;j;j--){
	if(id[r[j-1]]>id[r[j]]){
	  t=r[j];
	  r[j]=r[j-1];
	  r[j-1]=t;
	}
      }
    }
    for(i=0;i<n;i++){//printf("%lld\n",id[r[i]]);
      if(c<10){
	if(uc[u[r[i]]]<3){
	  uc[u[r[i]]]++;
	  c++;
	  printf("%lld\n",id[r[i]]%10000);
	}
      }
      else if(c<20){
	if(uc[u[r[i]]]<2){
	  uc[u[r[i]]]++;
	  c++;
	  printf("%lld\n",id[r[i]]%10000);
	}
      } 
      else if(c<26){
	if(uc[u[r[i]]]<1){
	  uc[u[r[i]]]++;
	  c++;
	  printf("%lld\n",id[r[i]]%10000);
	}
      }
    }
  }
  return 0;
}