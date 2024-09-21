#include<stdio.h>
int ans,wx,wy,rem;
int tab[10][10];
inline void solve(int nx,int ny,int rem){
    int nowx,nowy,*p,*pat=&tab[nx][ny];

    nowx=nx;nowy=ny;
    p=pat;
LA:
   nowx++;
   if(nowx>=wx) goto LB;
   p+=10;
   if(*p==2&&rem==0)ans++;
   else if(*p==1){
       *p=-1;
       solve(nowx,nowy,rem-1);
       *p=1;
       goto LB;
   }
   goto LA;
LB:         

    nowx=nx,nowy=ny;
    p=pat;
MA:
   nowx--;
   if(0>nowx) goto MB;
   p-=10;
   if(*p==2&&rem==0)ans++;
   else if(*p==1){
       *p=-1;
       solve(nowx,nowy,rem-1);
       *p=1;
       goto MB;
   }
   goto MA;
MB:         

    nowx=nx,nowy=ny;
    p=pat;
NA:
   nowy++;
   if(nowy>=wy) goto NB;
   p++;
   if(*p==2&&rem==0)ans++;
   else if(*p==1){
       *p=-1;
       solve(nowx,nowy,rem-1);
       *p=1;
       goto NB;
   }
   goto NA;
NB:        

    nowx=nx,nowy=ny;
    p=pat;
OA:
   nowy--;
   if(0>nowy) return;
   p--;
   if(*p==2&&rem==0)ans++;
   else if(*p==1){
       *p=-1;
       solve(nowx,nowy,rem-1);
       *p=1;
       return;
   }
   goto OA;
}
int main(){
    for(;;){
        int m,n;
        scanf("%d%d",&m,&n);
        if(m==0&&n==0)break;
        int stx,sty,homec=0;
        int i,j;
        for(i=0;i<n;i++)for(j=0;j<m;j++){
            scanf("%d",&tab[i][j]);
            if(tab[i][j]==1)homec++;
            else if(tab[i][j]==2){stx=i;sty=j;}
        }
        wx=n;wy=m;
        ans=0;
        solve(stx,sty,homec);
        printf("%d\n",ans);
    }
    return 0;
}