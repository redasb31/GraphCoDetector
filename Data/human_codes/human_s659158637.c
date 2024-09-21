#include<stdio.h>
#include<string.h>

main(){
  
  char s[10000];
  char this[10]="this";
  char that[10]="that";

  while(fgets(s,sizeof(s),stdin)!=NULL){
  
    int n,i;
  
    n=strlen(s);
  
  
    while(1){

      int co=0;
      
      for(i=0;i<n;i++){
	if(97<=s[i] && 122>=s[i]){
	  s[i]--;
	  if(s[i]==96){
	    s[i]=122;
	  }
	}
      }
    
      for(i=0;i<n;i++){
	if(s[i]==this[0]){
	  if(s[i+1]==this[1]){
	    if(s[i+2]==this[2]){
	      if(s[i+3]==this[3]){
		co=1;
	      }
	    }
	    else if(s[i+2]==that[2]){
	      if(s[i+3]==that[3]){
		co=1;
	      }
	    }
	  }
	}
      }

      if(co==1){
	break;
      }
      
    }
    printf("%s",s);
  }  
  return 0;
}