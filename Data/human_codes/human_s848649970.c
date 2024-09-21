#include <stdio.h>

int max(int data[],int n){
  int i,mm=0;
  for(i=0;i<n;i++){
    if(data[mm]<data[i]) mm=i;
  }
  return mm;
}

main(){
 int a[10],b[10],j,k,x,y,amax[3],bmax[3],aa=0,bb=0;
 
 for(j=0;j<10;j++){
    scanf("%d",&a[j]);
  }
 for(k=0;k<10;k++){
    scanf("%d",&b[k]);
  }

 for(x=0;x<3;x++){
    aa=max(a,10);
    amax[x]=a[aa];
    a[aa]=0;
  }
 for(y=0;y<3;y++){
    bb=max(b,10);
    bmax[y]=b[bb];
    b[bb]=0;
  }

 printf("%d %d\n",amax[0]+amax[1]+amax[2],bmax[0]+bmax[1]+bmax[2]);

return 0; 
}