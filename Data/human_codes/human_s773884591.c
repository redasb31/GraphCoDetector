#include<stdio.h>

typedef struct R{
  int h, w;
} Rect;

int solve(){
  Rect D[6], F[3], rtmp;
  int i, tmp, j, minj;
  for ( i = 0; i < 6; i++ ) {
    scanf("%d %d", &D[i].h, &D[i].w);
    if ( D[i].h > D[i].w) {
      tmp = D[i].h; D[i].h = D[i].w; D[i].w = tmp;
    }
  }
  for ( i = 0; i < 6; i++ ){
    minj = i;
    for ( j = i; j < 6; j++ ){
      if ( D[j].h <= D[minj].h ){
        if (D[j].h == D[minj].h ){
          if ( D[j].w < D[minj].w ) minj = j;
        } else minj = j;
      }
    }
    rtmp = D[minj]; D[minj] = D[i]; D[i] = rtmp;
  }


  for ( i = 0; i < 6; i+=2){
    if ( D[i].h == D[i+1].h && D[i].w == D[i+1].w ) D[i/2] = D[i];
    else return 0;
  }

  return D[0].h == D[1].h && D[0].w == D[2].h && D[1].w == D[2].w;
}

int main(){
  if ( solve() ) printf("yes\n");
  else printf("no\n");
  return 0;
}

