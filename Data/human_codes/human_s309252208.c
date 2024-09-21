#include<stdio.h>
int main()
{
  int t,i,n,k,h[101],nb,or,mxnb,mxor;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&n);
    mxnb=0;
    mxor=0;
    nb=0;
    or=0;
    for(k=0;k<n;k++){
      scanf("%d",&h[k]);
      if(k%2==1)nb=h[k]-h[k-1];
      else if(k%2==0&&k!=0)or=h[k]-h[k-1];
      if(mxnb<nb)mxnb=nb;
      if(mxor<or)mxor=or;
    }
    printf("%d %d\n",mxnb,mxor);
  }
  return 0;
}