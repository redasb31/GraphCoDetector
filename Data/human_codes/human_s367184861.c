#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INIVAL 2147483647

#define min(a,b) ((a)<(b)?(a):(b))

int *a, s, t, v, n, w, minval;

void find_min(int k, int l, int r)
{
  if (l>=n || r<=s || t<=l) return;
  if (s<=l && r<=t) {
    if (a[k]<minval)  minval = a[k];
  } else {
    if (a[((k+1)<<1)-1]>=0)  find_min(((k+1)<<1)-1, l, (l+r)>>1);
    if (a[(k+1)<<1]>=0)      find_min((k+1)<<1, (l+r)>>1, r);
    else if (a[k] < minval)  minval = a[k];
  }
}

void update_min(unsigned int k, unsigned int l, unsigned r)
{
  if (k>=w) return;
  update_min(k*2+1, l, (l+r)/2);
  update_min(k*2+2, (l+r)/2, r);
  int lval = k*2+1<n+w ? a[k*2+1] : INIVAL;
  int rval = k*2+2<n+w ? a[k*2+2] : INIVAL;
  a[k] = min(lval, rval);
}

int main()
{
  int i, l;
  char *p, buf[64] = {0};
  fgets(buf, 64, stdin);
  for (n=0,p=buf; *p>' '; n=n*10+*(p++)-'0');
  for (l=0,p++  ; *p>' '; l=l*10+*(p++)-'0');
  w = n>1 ? pow(2,(int)ceil(log2(n)))-1 : 0;
  a = (int*)malloc(sizeof(int)*(w+n));
  for (i=0; i<w+n; i++)  a[i] = INIVAL;
  for (i=w; i<w+n; i++) {
    scanf("%d", &a[i]);
  }
  s = 0; t = n;
  update_min(0, 0, w+1);

  for (s=0; s<=n-l; s++) {
    t = s+l;
    minval = INIVAL;
    find_min(0, 0, w+1);
    if (minval<10) {
      putc_unlocked('0'+minval, stdout);
    } else {
      for (i=63; minval>0; buf[--i]='0'+minval%10,minval/=10);
      fputs(buf+i, stdout);
    }
    if (s<n-l) putc_unlocked(' ', stdout);
  }
  putc_unlocked('\n', stdout);
  return 0;
}

