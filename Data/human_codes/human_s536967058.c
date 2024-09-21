#include <stdio.h>

struct page{
  char name[210];
  int a,bob,boe;
};
struct botan{
  char name[210];
  int lux,luy,rdx,rdy;
};

main(){
  int n,m,i,j,k,W,H,a,c,bo,cx,cy,jud=0,where=0,namec=0,l;
  char com[80];
  struct botan b[90201];
  struct page p[901];
  while(1){
    bo=0;
    scanf("%d",&n);
    if(n==0) break;
    scanf("%d%d",&W,&H);
    for(i=0;i<n;i++){
      scanf("%s%d",p[i].name,&c);
      p[i].a=0;
      p[i].bob=bo;
      for(j=0;j<c;j++){
	scanf("%d%d%d%d%s",&b[bo].lux,&b[bo].luy,&b[bo].rdx,&b[bo].rdy,b[bo].name);
	bo++;
      }
      p[i].boe=bo;
    }

    p[0].a=0;
    a=0;
    where=0;
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%s",com);
      /*       printf("mae %d\n",a); */
      if(com[0]=='b'&&a>0){ 
	a--;
	for(j=0;j<n;j++){
	  if(a==p[j].a){
	    where=j;
	    break;
	  }
	}
      }
      else if(com[0]=='f'&&a<n-1){ 
	a++;
	for(j=0;j<n;j++){
	  if(a==p[j].a){
	    where=j;
	    break;
	  }
	}
      }
      else if(com[0]=='c'){
	scanf("%d%d",&cx,&cy);
	for(j=p[where].bob;j<p[where].boe;j++){
	  jud=0;
	  /*	  printf("+\n"); */
	  if(b[j].lux<=cx&&cx<=b[j].rdx&&b[j].luy<=cy&&cy<=b[j].rdy){
	    namec=0;	    
	    for(k=0;k<n;k++){
	      for(l=0;l<21;l++){	    
		if(p[k].name[l]==b[j].name[l]) namec++;
		if(p[k].name[l]=='\0'||b[j].name[l]=='\0'){
		  l++;
		  break;
		}
	      }
	      /*printf("l=%d namec=%d\n",l,namec);*/
	      if(l==namec){
		p[k].a=++a;
		jud=1;
		where=k;
		/*printf("cy:%d,luy=%d,rdy=%d j=%d \n",cy,b[j].luy,b[j].rdy,j); */
		break;
	      }
	    }		
	  }
	}
	if(jud==1) break;
      }
      else if(com[0]=='s'){
	for(j=0;j<n;j++){
	  if(a==p[j].a) {
	    printf("%s\n",p[j].name);
	    break;
	  }
	  /* else printf("a=%d p[j].a=%d\n",a,p[j].a);*/
	}
      }
      /*printf("ato\n);*/
    }
  }
  return 0;
}