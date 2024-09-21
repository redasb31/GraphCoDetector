/*
  AOJ 2524
  Title:Mysterious Operator
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
char buf[11]; 

main()
{
  int i,j,len,ret,parity,fm,lt;
  char buf2[11];
  scanf("%s",&buf[0]);
  len=strlen(buf);
  ret=((buf[len-1]&1)?0:1);
  //printf("ret1=%d\n",ret);
  //count digits whose parity is same as last digit 
  if(len>1)
    {
      parity=(buf[len-1] & 1);
      for(j=len-2;j>=((buf[0]=='-')?1:0);j--)
	{
	  if(buf[j+1]=='0')
	    continue;
	  if(parity==(buf[j]&1))
	    if(buf[0]=='-')
	      ret++;
	    else
	      {
		lt=atoi(&buf[j+1]);
		strcpy(buf2,buf);
		buf2[j+1]='\0';
		fm=atoi(buf2);
		//printf("fm=%d lt=%d\n",fm,lt);
		if(fm<=lt)
		  ret++;
	      }
	}
    }
  printf("%d\n",ret);
      
  return(0);
}