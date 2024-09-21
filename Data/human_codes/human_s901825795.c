#include <stdio.h>
#include <stdlib.h>

typedef int wint[2];

int compar(wint *a, wint *b)
{
  if ((double)((*a)[0])/(*a)[1] < (double)((*b)[0])/(*b)[1]) return 1;
  if ((double)((*a)[0])/(*a)[1] > (double)((*b)[0])/(*b)[1]) return -1;
  else return 0;
}

int main()
{
    int i, n, w;
    char buf[32];
    scanf("%d %d\n", &n, &w);

    int val[n][2];
    char *p;
    for (i=0; i<n; i++) {
      fgets(buf, 32, stdin);
      for (val[i][0]=0,p=buf; *p!=' ';  val[i][0] = val[i][0] * 10 + *(p++) - '0');
      for (val[i][1]=0,p++;   *p!='\n'; val[i][1] = val[i][1] * 10 + *(p++) - '0'); 
    }
    
    double total=0;
    qsort(val, n, sizeof(int)*2, (int(*)(const void*, const void*))compar);
    for (i=0; i<n; i++) {
       if (w>=val[i][1]) {
        w -= val[i][1];
        total += val[i][0];
      }	else {
	 total += (double)w*val[i][0]/val[i][1];
	 break;
      }
    }
    printf("%.12f\n", total);
    
    return 0;
}

