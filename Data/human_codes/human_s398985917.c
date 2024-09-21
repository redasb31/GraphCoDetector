#include<stdio.h>
#include<stdbool.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

void solve(int m,int n);

int main(void){
  int m,n;
  while(scanf("%d%d",&m,&n) && m && n ) solve(m,n);
  return 0;
}

void solve(int m,int n){
  int t[100],out[100];
  int now,i,j,k,dt,incar=0,outcar=0;
  bool flg;
  struct p{
    int time,num;
  } park[10][2],minpark;
  
  for(i=0;i<n;i++) scanf("%d",&t[i]);
  for(i=0;i<10;i++) for(j=0;j<2;j++) park[i][j]=(struct p){0,0};
  
  for(now=0;outcar<n;now+=dt){
    //fprintf(stderr,"(t,in,out)=(%d,%d,%d)\n",now,incar,outcar);
    //for(i=0;i<m;i++) fprintf(stderr,"\t[%d,%d]\t[%d,%d]\n",park[i][0].time,park[i][0].num,park[i][1].time,park[i][1].num);
    if(now>1000) return;
			    
    while(now>=incar*10 && incar<n){
      if(incar-outcar<2*m){
	flg=true;
	for(i=0;i<m;i++){
	  if(park[i][0].num==0){
	    park[i][0]=(struct p){t[incar],incar+1};
	    flg=false;
	    break;
	  }
	}
	if(flg){
	  //fputs("in flg-if\n",stderr);
	  minpark=(struct p){1000,-1};
	  for(i=0;i<m;i++)
	    if(park[i][1].num==0 && park[i][0].time>=t[incar])
	      if(minpark.time>park[i][0].time-t[incar])
		minpark=(struct p){park[i][0].time-t[incar],i};
	  if(minpark.num!=-1) park[minpark.num][1]=(struct p){t[incar],incar+1};
	  else{
	    for(i=0;i<m;i++)
	      if(park[i][1].num==0 && minpark.time>t[incar]-park[i][0].time)
		minpark=(struct p){t[incar]-park[i][0].time,i};
	    park[minpark.num][1]=(struct p){t[incar],incar+1};
	    park[minpark.num][0].time=t[incar];
	  }
	}
	incar++;
      }else break;
    }
    
    dt=10;
    for(i=0;i<m;i++){
      if(park[i][1].num!=0 && park[i][1].time<dt) dt=park[i][1].time;
      else if(park[i][0].num!=0 && park[i][0].time<dt) dt=park[i][0].time;
    }
 
    for(i=0;i<m;i++){
      for(j=1;j>=0;j--){
	if(park[i][j].num!=0){
	  park[i][j].time-=dt;
	  if(park[i][j].time==0){
	    out[outcar++]=park[i][j].num;
	    park[i][j]=(struct p){0,0};
	  }
	}
      }
    }
    //fputc('\n',stderr);
  }

  for(i=0;i<outcar;i++) printf("%d%c",out[i],i==outcar-1?'\n':' ');
  
}