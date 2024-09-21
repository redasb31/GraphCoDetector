/*
  AOJ 2090
  Title:Repeated Subsequences
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

void longest_common_sunseq(char *in1,char *in2,char *out)
{
  char buf1[151],buf2[151],outbuf1[151],outbuf2[151],*result;

  //printf("%s:%s\n",in1,in2);

  if(!*in1 || !*in2)
    {
      *out='\0';
      return;
    }
   
  if(*in1==*in2)
    {
      *outbuf1=*in1;
      longest_common_sunseq(in1+1,in2+1,outbuf1+1);
      result=outbuf1;
    }
  else
    {
      longest_common_sunseq(in1  ,in2+1,outbuf1);
      longest_common_sunseq(in1+1,in2  ,outbuf2);
      if(strlen(outbuf1)>strlen(outbuf2))
	result=outbuf1;
      else
	result=outbuf2;
    }
  strcpy(out,result);
}


main()
{
  char in1[301],in2[301],out[151],result[151];
  int len,len2,max_,i;

  while(scanf("%s",in1) && 0!=strcmp("#END",in1))
    {
      *result='\0';
      len=strlen(in1);
      for(i=1,max_=0;i<len-1;i++)
	{
	  strncpy(in2,in1,i);
	  in2[i]='\0';
	  longest_common_sunseq(in2,in1+i,out);
	  len2=strlen(out);
	  if(max_<len2)
	    {
	      max_=len2;
	      strcpy(result,out);
	    }
	}
      printf("%s\n",result);
    }
  return(0);
}