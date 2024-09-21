#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(long a[],int l,int r);
int quicksort(long a[],int l,int r);
int partition2(long a[],int b[],int l,int r);
int quicksort2(long a[],int b[],int l,int r);

int main(void){
  int N,M,b[100005],i,n,j;
  long sum,c[100005],a[100005];
  char str[1100000],*p;
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  N=atoi(p);
  p=strtok(NULL," \n");
  M=atoi(p);
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  a[0]=atol(p);
  for(i=1;i<N;i++){
    p=strtok(NULL," \n");
    a[i]=atol(p);
  }
  
  for(i=0;i<M;i++){
    fgets(str,sizeof(str),stdin);
    p=strtok(str," \n");
    b[i]=atoi(p);
    p=strtok(NULL," \n");
    c[i]=atol(p);
  }
  
  quicksort(a,0,N-1);
  
  for(i=0;i<N;i++){
  }
  
  quicksort2(c,b,0,M-1);
  for(i=0;i<M;i++){
  }
  
  n=0,i=0;
  
  while(i<N){
    if(n+b[i]>N-1){
      if(a[N-1]<b[i]){
        for(j=n;j<N;j++){
          a[n]=c[i];
        }
      }else{
        break;
      }
    }
    if(a[n+b[i]]>c[i]){
      break;
    }else{
      for(j=0;j<b[i];j++){
        a[n+j]=c[i];
        
      }
      n+=b[i];
    }
    i++;
  }
  
  while(a[n]<c[i]){
    a[n]=c[i];
    n++;
  }
  
  for(i=0,sum=0;i<N;i++){
    sum+=a[i];
  }
  printf("%ld\n",sum);
  
  
  return 0;
}

int partition(long a[],int l,int r){
    int i,j,bbuff;
    long abuff,pivot;
    
    i=l-1,j=r;
    pivot=a[r];
    for(;;){
        while(a[++i]<pivot);
        
        while(i<=--j && a[j]>=pivot);
        
        if(i>=j){
            abuff=a[r],a[r]=a[i],a[i]=abuff;
            break;
        }
        
        abuff=a[i],a[i]=a[j],a[j]=abuff;
        
    }
    
    return i;
}

int quicksort(long a[],int l,int r){
    int v;
    
    if(l>=r){
        return 0;
    }
    
    v=partition(a,l,r);
    
    quicksort(a,l,v-1);
    quicksort(a,v+1,r);
    
    return 0;
    
}


int partition2(long a[],int b[],int l,int r){
    int i,j,bbuff;
    long abuff,pivot;
    
    i=l-1,j=r;
    pivot=a[r];
    for(;;){
        while(a[++i]>pivot);
        
        while(i<=--j && a[j]<=pivot);
        
        if(i>=j){
            abuff=a[r],a[r]=a[i],a[i]=abuff;
            bbuff=b[r],b[r]=b[i],b[i]=bbuff;
            break;
        }
        
        abuff=a[i],a[i]=a[j],a[j]=abuff;
        bbuff=b[i],b[i]=b[j],b[j]=bbuff;
        
    }
    
    return i;
}

int quicksort2(long a[],int b[],int l,int r){
    int v;
    
    if(l>=r){
        return 0;
    }
    
    v=partition2(a,b,l,r);
    
    quicksort2(a,b,l,v-1);
    quicksort2(a,b,v+1,r);
    
    return 0;
    
}