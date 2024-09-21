#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000

//具体的に考えることも重要だが、抽象的に数学で考えてみることも重要。
//置換群の問題

void merge_sort(int *t1, int *s1, int left, int right){
    if(left==right){
        ;
    }
    else{
        int n2=(right-left+1)/2;
        int n3=right-left+1-n2;
        int i=0,j=0,k=0;

        merge_sort(t1, s1, left, left+n2-1);
        merge_sort(t1, s1, left+n2, right);

        int *t2=(int *)malloc(sizeof(int)*n2);
        int *t3=(int *)malloc(sizeof(int)*n3);
        int *s2=(int *)malloc(sizeof(int)*n2);
        int *s3=(int *)malloc(sizeof(int)*n3);

        for(i=0;i<n2;i++){
          t2[i]=t1[left+i];
          s2[i]=s1[left+i];
        }
        for(i=0;i<n3;i++){
          t3[i]=t1[left+n2+i];
          s3[i]=s1[left+n2+i];
        }

        //ここの実装にn時間かかった。定義されていない領域にアクセスしないの重要。
        for(i=0;i<n2+n3;i++){
            if(k==n3 || (j<n2 && t2[j]<t3[k])){
                t1[left+i]=t2[j];
                s1[left+i]=s2[j];
                j++;
            }
            else{
                t1[left+i]=t3[k];
                s1[left+i]=s3[k];
                k++;
            }
        }
    }
}


//置換の積 (p^a)(q^b) を計算する
//置換は(0~N-1)で構成されているとする。
void replace(int N, int *p, int a, int *q, int b, int *pro2){
  int *temp=(int *)malloc(sizeof(int)*N);
  int *p1=(int *)malloc(sizeof(int)*N);
  int *q1=(int *)malloc(sizeof(int)*N);
  int *p2=(int *)malloc(sizeof(int)*N);
  int *q2=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    p1[i]=i;
    q1[i]=i;
    p2[i]=p[i];
    q2[i]=q[i];
  }


  if(a==-1 && b==-1){
    merge_sort(p2, p1, 0, N-1);
    merge_sort(q2, q1, 0, N-1);
    rep(i,N){
      temp[i]=p1[q1[i]];
    }
    rep(i,N){
      pro2[i]=temp[i];
    }
  }
  else if(a==1 && b==-1){
    merge_sort(p1, p2, 0, N-1);
    merge_sort(q2, q1, 0, N-1);
    rep(i,N){
      temp[i]=p2[q1[i]];
    }
    rep(i,N){
      pro2[i]=temp[i];
    }
  }
  else if(a==-1 && b==1){
    merge_sort(p2, p1, 0, N-1);
    merge_sort(q1, q2, 0, N-1);
    rep(i,N){
      temp[i]=p1[q2[i]];
    }
    rep(i,N){
      pro2[i]=temp[i];
    }
  }
  else{
    // printf("p2 = ");
    // rep(i,N){
    //   printf("%d ", p2[i]);
    // }
    // printf("\n");
    // printf("q2 = ");
    // rep(i,N){
    //   printf("%d ", q2[i]);
    // }
    // printf("\n");
    merge_sort(p1, p2, 0, N-1);
    merge_sort(q1, q2, 0, N-1);

    rep(i,N){
      temp[i]=p2[q2[i]];
    }
    rep(i,N){
      pro2[i]=temp[i];
    }
  }
}

//AとBを求める
void make(int N, int *p2, int *q2, int *A2, int *B2, int eqo, int rest, int *pro2){
  if(eqo==0){
    rep(i,N){
      A2[i]=i;
    }
  }
  else if(eqo==1){
    rep(i,N){
      A2[i]=pro2[i];
    }
  }
  else{
    rep(i,N){
      A2[i]=pro2[i];
    }
    rep(i,eqo-1){
      replace(N, A2, 1, pro2, 1, A2);
    }
  }


  if(rest==1){
    rep(i,N){
      B2[i]=p2[i];
    }
  }
  else if(rest==2){
    rep(i,N){
      B2[i]=q2[i];
    }
  }
  else if(rest==3){
    replace(N, q2, 1, p2, -1, B2);
  }
  else if(rest==4){
    replace(N, A2, 1, q2, 1, A2);
    int *p1=(int *)malloc(sizeof(int)*N);
    rep(i,N){
      p1[i]=i;
    }
    replace(N, p1, 1, p2, -1, B2);
  }
  else if(rest==5){
    replace(N, A2, 1, q2, 1, A2);
    // printf("A2 = ");
    // rep(i,N){
    //   printf("%d ", A2[i]);
    // }
    // printf("\n");
    replace(N, A2, 1, p2, -1, A2);
    int *q1=(int *)malloc(sizeof(int)*N);
    rep(i,N){
      q1[i]=i;
    }
    replace(N, q1, 1, q2, -1, B2);
  }
  else{
    replace(N, A2, 1, q2, 1, A2);
    replace(N, A2, 1, p2, -1, A2);
    replace(N, q2, -1, p2, 1, B2);
  }
}



int main(){
  char buf[1024];
  int N,K;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &K);

  int *p2=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    scanf("%d",&p2[i]);
    p2[i]--;
  }

  int *q2=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    scanf("%d",&q2[i]);
    q2[i]--;
  }

  int *pro1=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    pro1[i]=i;
  }
  int *pro2=(int *)malloc(sizeof(int)*N);

  replace(N, q2, -1, p2, 1, pro2);
  replace(N, p2, -1, pro2, 1, pro2);
  replace(N, q2, 1, pro2, 1, pro2);

  // rep(i,N){
  //   printf("%d ", pro2[i]+1);
  // }
  // printf("\n");

  int eqo=(K-1)/6;
  int rest=K%6;


  int *A2=(int *)malloc(sizeof(int)*N);
  int *B2=(int *)malloc(sizeof(int)*N);

  make(N, p2, q2, A2, B2, eqo, rest, pro2);

  // printf("A2 = ");
  // rep(i,N){
  //   printf("%d ", A2[i]);
  // }
  // printf("\n");
  // printf("B2 = ");
  // rep(i,N){
  //   printf("%d ", B2[i]);
  // }
  // printf("\n");


  int *a=(int *)malloc(sizeof(int)*N);
  replace(N, A2, 1, B2, 1, a);
  replace(N, a, 1, A2, -1, a);

  rep(i,N){
    a[i]++;
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
