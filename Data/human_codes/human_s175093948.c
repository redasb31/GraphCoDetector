#include<stdio.h>
#define min(x,y) ((x) < (y) ? (x) : (y))
 
int main(){
    int ch,a,b,c,d,e,f,g;
    a=b=c=d=0;
    while((ch=getchar())!=EOF){
                switch(ch){
                        case 'K':a++;
                        break;
                        case 'U':b++;
                        break;
                        case 'P':c++;
                        break;
                        case 'C':d++;
                        break;
                        default:
                        break;
                }
        }
        e=min(a,b);
        f=min(c,d);
        g=min(e,f);
        printf("%d\n",g); 
        return 0;
}