//2008dC
I;int parse(char *p){
  switch(*p){
    case 'F': return 0;
    case 'T': return 1;
    case 'a': return (I>>0)&1;
    case 'b': return (I>>1)&1;
    case 'c': return (I>>2)&1;
    case 'd': return (I>>3)&1;
    case 'e': return (I>>4)&1;
    case 'f': return (I>>5)&1;
    case 'g': return (I>>6)&1;
    case 'h': return (I>>7)&1;
    case 'i': return (I>>8)&1;
    case 'j': return (I>>9)&1;
    case 'k': return (I>>10)&1;
    case '-': return !parse(p+1);
    case '(': {
                int x=0;
                p++;
                char *q=p;
                for(;;p++){
                  if(*p=='(')x++;
                  if(*p==')')x--;
                  if(x==0&&*p!='-')break;
                }
                p++;
                switch(*p){
                  case '*': return parse(q)&parse(p+1);
                  case '+': return parse(q)|parse(p+1);
                  case '-': return !parse(q)|parse(p+2);
                }
              }
  }
}

char p[1001],*q;main(){for(;scanf("%s",p),*p-'#';puts(I==2048?"YES":"NO")){
	q=strchr(p,'=')+1;
	for(I=0;I<2048;I++)if(parse(p)!=parse(q))break;
}exit(0);}