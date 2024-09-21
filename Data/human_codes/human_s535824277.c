#include<stdio.h>
#include<string.h>

char moji(char x){
  if(x=='T') x='a';
  if(x=='L') x='i';
  if(x=='U') x='u';
  if(x=='R') x='e';
  if(x=='D') x='o';
  return x;
}


int main(){
  char a[1000],b[1000];
  int i,j,len,t=0;


    scanf("%s",a);
  
  len=strlen(a);

  for(i=0;i<len;i++){
    if(a[i]=='0'){
        if(a[i+1]!='U' && a[i+1]!='L' && a[i+1]!='R'){
      b[t]='w';
      t++;
      b[t]=moji(a[i+1]);
      t++;
      }
	
      if(a[i+1]=='U'){
	b[t]='n';
	t++;
	b[t]='n';
	t++;
      }
    }
    else if(a[i]=='1'){
      b[t]=moji(a[i+1]);
      t++;
    }

    else if(a[i]=='2'){
	b[t]='k';
	t++;
	b[t]=moji(a[i+1]);
	t++;
      }
    else if(a[i]=='3'){
      b[t]='s';
      t++;
	b[t]=moji(a[i+1]);
      t++;
    }

    else if(a[i]=='4'){
      b[t]='t';
      t++;
      b[t]=moji(a[i+1]);
      t++;
    }
    else if(a[i]=='5'){
      b[t]='n';
      t++;
      b[t]=moji(a[i+1]);
      t++;
    }
    else if(a[i]=='6'){
      b[t]='h';
      t++;
      b[t]=moji(a[i+1]);
      t++;
      
    }
    else if(a[i]=='7'){
      b[t]='m';
      t++;
      b[t]=moji(a[i+1]);
      t++;
    }
    else if(a[i]=='8'){
      if(a[i+1]!='L' && a[i+1]!='R'){
      b[t]='y';
      t++;
      b[t]=moji(a[i+1]);
      t++;
      }
    }

    else if(a[i]=='9'){
      b[t]='r';
      t++;
      b[t]=moji(a[i+1]);
      t++;
    }
  }
  for(i=0;i<t;i++){
    printf("%c",b[i]);
  }
  printf("\n");

  return 0;
}

    