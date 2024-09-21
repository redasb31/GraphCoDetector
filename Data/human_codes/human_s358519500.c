#include<stdio.h>

long long pow(long long a,long long x){
    long long i,r=1;
    for(i=1;i<=x;i++){r*=a;}
    return r;
}

int main(void){
    long long dt,ds=1,df=10,r1,r2;
    long long rt,rs,rf;
    char s[8];
    while(1){
        dt=(ds+df)/2;r1=0;r2=0;
        printf("? %lld\n",pow(10,dt-1));
        fflush(stdout);scanf("%s",s);
        if(s[0] == 'Y'){r1++;}
        printf("? %lld\n",pow(10,dt)-1);
        fflush(stdout);scanf("%s",s);
        if(s[0] == 'Y'){r2++;}
        if(r1 && r2){break;}
        if(r1){ds=dt+1;}else{df=dt-1;}
    }
    if(dt==10){
        printf("! 1000000000\n");
        fflush(stdout);
        return 0;
    }
    rs=pow(10,dt-1);rf=pow(10,dt)-1;
    while(rs!=rf){
        rt=(rs+rf)/2;r1=0;
        printf("? %lld9\n",rt);
        fflush(stdout);scanf("%s",s);
        if(s[0] == 'Y'){r1++;}
        if(r1){rf=rt-1;}else{rs=rt;}
    }
    printf("! %lld\n",rs);
    fflush(stdout);
    return 0;
}