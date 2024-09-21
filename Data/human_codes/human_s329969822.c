#include <stdio.h>
#include <math.h>

int main(void){
  double xp1,xp0,yp1,yp0,xp2,yp2;
  int q;
  scanf("%lf %lf %lf %lf",&xp0,&yp0,&xp1,&yp1);
  scanf("%d",&q);
  double z,k;
  for(int i=0;i<q;i++){
    scanf("%lf %lf",&xp2,&yp2);
    z=(xp1-xp0)*(yp2-yp0)-(yp1-yp0)*(xp2-xp0);
    if(z>0){
      printf("COUNTER_CLOCKWISE\n");
    }
    else if(z<0){
      printf("CLOCKWISE\n");
    }
    else{
      if(xp1==xp0){
        k=(yp1-yp0)/(yp2-yp0);
      }
      else{
        k=(xp1-xp0)/(xp2-xp0);
      }
      if(k<0){
        printf("ONLINE_BACK\n");
      }
      else if(k<1){
        printf("ONLINE_FRONT\n");
      }
      else{
        printf("ON_SEGMENT\n");
      }
    }
  }
  return 0;
}

