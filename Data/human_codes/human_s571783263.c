#include <stdio.h>

int main()
{
  int nq, i, j, m, n, count = 0;
  unsigned long w[64];
  w[0]=1;
  for (i=1; i<64; i++) 
    w[i]=w[i-1]*2;
  char buf[192];
  buf[191]='\0';
  buf[190]='\n';
  char a[64] = {0};
  unsigned long val;
  fgets(buf, 32, stdin);
  char *p = buf;
  for (n=0; *p>='0'; p++)  n = n * 10 + *p - '0';
  char masks[n][65];
  for (i=0;i<n;i++) for(j=0;j<65;j++) masks[i][j]=0;

  for (i=0; i<n; i++) {
    fgets(buf, 190, stdin);
    p = buf;
    masks[i][0]=0;
    j=0;
    for (m=0; *p!='\n'; p++) {
      if (*p == ' ') {
	masks[i][++j] = *(++p)-'0';
      } else {
	masks[i][j] = masks[i][j] * 10 + *p - '0';
      }
    }
  }

  p = fgets(buf, 32, stdin);
  for (nq=0; *p>='0'; p++)  nq = nq * 10 + *p - '0';
  while (nq-->0) {
    fgets(buf, 192, stdin);
    switch (buf[0]-'0') {
    case 0: // test(i)
      i = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      fputs(a[i]?"1\n":"0\n", stdout);
      break;
    case 1: // set(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1; i<=masks[m][0]; i++)	a[(int)masks[m][i]]=1;
      break;
    case 2: // clear(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1; i<=masks[m][0]; i++)	a[(int)masks[m][i]]=0;
      break;
    case 3: // flip(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1;i<=masks[m][0];i++) {
	if (a[(int)masks[m][i]]) a[(int)masks[m][i]]=0;
	else a[(int)masks[m][i]]=1;
      }
      break;
    case 4: // all(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1;i<=masks[m][0];i++) {
	if (a[(int)masks[m][i]]==0) {
	  fputs("0\n", stdout);
	  break;
	}
      }
      if (i==masks[m][0]+1) fputs("1\n", stdout);
      break;
    case 5: // any(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1;i<=masks[m][0];i++) {
	if (a[(int)masks[m][i]]) {
	  fputs("1\n", stdout);
	  break;
	}
      }
      if (i==masks[m][0]+1) fputs("0\n", stdout);
      break;
    case 6: // none(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      for (i=1;i<=masks[m][0];i++) {
	if (a[(int)masks[m][i]]) {
	  fputs("0\n", stdout);
	  break;
	}
      }
      if (i==masks[m][0]+1)  fputs("1\n", stdout);
      break;
    case 7: // count(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      count = 0;
      for (i=1; i<=masks[m][0]; i++)
	if (a[(int)masks[m][i]]) count++;

      if (count==0) {
	fputs("0\n", stdout);
      } else {
	for (j=189; count>0; j--, count/=10)   buf[j] = '0' + (count%10);
	fputs(buf+j+1, stdout);
      }
      break;
    case 8: // val(m)
      m = (buf[3]=='\n') ? buf[2]-'0' : (buf[2]-'0')*10+buf[3]-'0';
      val = 0;
      for (i=1;i<=masks[m][0];i++) {
	if (a[(int)masks[m][i]])
	  val += w[(int)masks[m][i]];
      }
      if (val==0) {
	fputs("0\n", stdout);
      } else {
	for (j=189; val>0; j--, val/=10)   buf[j] = '0' + (val%10);
	fputs(buf+j+1, stdout);
      }
    }
  }
  return 0;
}

