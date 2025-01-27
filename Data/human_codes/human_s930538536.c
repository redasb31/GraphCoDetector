#include <stdio.h>
#include <math.h>

int main(void){
    int n,count=0;
    int ax[205],ay[205],bx[205],by[205];
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d%d",&ax[i],&ay[i]);
    }    
    for(int i=1; i<=n; i++){
        scanf("%d%d",&bx[i],&by[i]);
    }

    //blueのyソート
    for(int i=1; i<=n; i++){
        int temx=bx[i],temy=by[i],temp=0;
        for(int j=i+1; j<=n; j++){
            if(temy > by[j]){
                temx=bx[j],temy=by[j],temp=j;
            }
        }
        if(temp){
            bx[temp]=bx[i],by[temp]=by[i];
            bx[i]=temx,by[i]=temy;
        }
    }

    for(int i=1; i<=n; i++){
        int temx=-1, temy=-1, temp=0;
        //blueのi※
        for(int j=1; j<=n; j++){
            //redのチェック
            if(ax[j]<bx[i] && ay[j]<by[i]){
                if(temx < ax[j]){
                    temx=ax[j],temy=ay[j],temp=j;
                }
            }
        }
        if(temp){
            count++;
            ax[temp]=300,ay[temp]=300;
        }
    }
    printf("%d\n",count);
    return 0;
}