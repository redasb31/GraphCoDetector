#include <stdio.h>
#include <math.h>

double gaiseki(double,double,double,double);

main(){
  double x[6], y[6], tenx[3], teny[3], len[3], s, m1, m2, ans, bx[5], by[5], temp1, temp2;
  int i, j, p=0, f, a;

  while(1){
    for(i=0;i<6;i+=2){
      scanf("%lf %lf %lf %lf", &x[i], &y[i], &x[i+1], &y[i+1]);
      if(x[0]==0 && y[0]==0 && x[1]==0 && y[1]==0){
	p=1;
	break;
      }
    }
    if(p==1) break;
    f=0;
    
    bx[0]=x[2]-x[3];
    by[0]=y[2]-y[3];
    bx[1]=x[2]-x[0];
    by[1]=y[2]-y[0];
    bx[2]=x[2]-x[1];
    by[2]=y[2]-y[1];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }
    bx[0]=x[0]-x[1];
    by[0]=y[0]-y[1];
    bx[1]=x[0]-x[2];
    by[1]=y[0]-y[2];
    bx[2]=x[0]-x[3];
    by[2]=y[0]-y[3];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }

    bx[0]=x[4]-x[5];
    by[0]=y[4]-y[5];
    bx[1]=x[4]-x[2];
    by[1]=y[4]-y[2];
    bx[2]=x[4]-x[3];
    by[2]=y[4]-y[3];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }
    bx[0]=x[2]-x[3];
    by[0]=y[2]-y[3];
    bx[1]=x[2]-x[5];
    by[1]=y[2]-y[5];
    bx[2]=x[2]-x[4];
    by[2]=y[2]-y[4];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }

    bx[0]=x[0]-x[1];
    by[0]=y[0]-y[1];
    bx[1]=x[0]-x[4];
    by[1]=y[0]-y[4];
    bx[2]=x[0]-x[5];
    by[2]=y[0]-y[5];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }
    bx[0]=x[4]-x[5];
    by[0]=y[4]-y[5];
    bx[1]=x[4]-x[1];
    by[1]=y[4]-y[1];
    bx[2]=x[4]-x[0];
    by[2]=y[4]-y[0];
    temp1=gaiseki(bx[0],by[0],bx[1],by[1]);
    temp2=gaiseki(bx[0],by[0],bx[2],by[2]);
    if(temp1*temp2>=0){
      printf("kyo\n");
      continue;
    }



    m1=(y[1]-y[0])/(x[1]-x[0]);
    m2=(y[3]-y[2])/(x[3]-x[2]);
    
    tenx[0]=(m1*x[0]-m2*x[2]+y[2]-y[0])/(m1-m2);
    teny[0]=m1*(tenx[0]-x[0])+y[0];

    m1=(y[3]-y[2])/(x[3]-x[2]);
    m2=(y[5]-y[4])/(x[5]-x[4]);

    tenx[1]=(m1*x[2]-m2*x[4]+y[4]-y[2])/(m1-m2);
    teny[1]=m1*(tenx[1]-x[2])+y[2];

    m1=(y[5]-y[4])/(x[5]-x[4]);
    m2=(y[1]-y[0])/(x[1]-x[0]);

    tenx[2]=(m1*x[4]-m2*x[0]+y[0]-y[4])/(m1-m2);
    teny[2]=m1*(tenx[2]-x[4])+y[4];
    

    if((tenx[0]==tenx[1] && teny[0]==teny[1]) || tenx[1]==tenx[2] && (teny[1]==teny[2]) || (tenx[2]==tenx[0] && teny[2]==teny[0])){
      printf("kyo\n");
      continue;
    }
   
    for(i=0,j=1;i<3;i++,j++){
      if(j==3) j=0;
      len[i]=sqrt((tenx[i]-tenx[j])*(tenx[i]-tenx[j])+(teny[i]-teny[j])*(teny[i]-teny[j]));
    }
    

    s=(len[0]+len[1]+len[2])/2;
    ans=sqrt(s*(s-len[0])*(s-len[1])*(s-len[2]));
    
    a=ans+0.0000001;
    if(ans>=1900000) printf("dai-kichi\n");
    else if(ans>=1000000) printf("chu-kichi\n");
    else if(ans>=100000) printf("kichi\n");
    else if(ans>0) printf("syo-kichi\n");
  }
  return 0;
}



double gaiseki(double a, double b, double c, double d){
  return (a*d-b*c);
}