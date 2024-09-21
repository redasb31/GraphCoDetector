#include <stdio.h>

int ruijou(int);

main(){
  int data[8][8], num[8]={4,1,4,1,2,1,2,1};
  int i, j, k, ans[8], p[8], sum[8], temp, v[8], a=0;

  for(i=0;i<8;i++){
    k=i;
    for(j=0;j<8;j++,k++){
      if(k==8) k=0;
      data[i][j]=num[k];
    }
  }

  while(1){
    if(scanf("%d", &p[0])==EOF){
      //printf("\n");
      break;
    }
    //if(a==1) printf(" \n");
    for(i=1;i<8;i++){
      scanf("%d", &p[i]);
    }
    
    for(i=0;i<8;i++){
      sum[i]=0;
      ans[i]=-1;
      v[i]=0;
    }
    
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
	temp=p[j]-data[i][j];
	if(temp<0) temp=0;
	sum[i]+=temp;
      }
    }

    temp=20;

    for(i=0;i<8;i++){
      if(temp>sum[i]) temp=sum[i];
    }

    for(i=0,j=0;i<8;i++){
      if(sum[i]==temp){
	ans[j]=i;
	j++;
      }
    }

    if(j==1){
      printf("%d", data[ans[0]][0]);
      for(i=1;i<8;i++){
	printf(" %d", data[ans[0]][i]);
      }
      printf(" \n");
    }

    else{
      for(i=0;i<j;i++){
	for(k=0;k<8;k++){
	  v[i]+=data[ans[i]][k]*ruijou((8-k));
	}
      }
      temp=-1;
      k=0;
      for(i=0;i<j;i++){
	if(temp==-1 || temp>v[i]){
	  temp=v[i];
	  k=i;
	}
      }
      printf("%d", data[ans[k]][0]);
      for(i=1;i<8;i++){
	printf(" %d", data[ans[k]][i]);
      }
      printf(" \n");
    }
    a=1;
  }
  return 0;
}

int ruijou(int a){
  int sum=1,i;
  
  for(i=0;i<a;i++){
    sum*=10;
  }
  return sum;
}