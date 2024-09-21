#include <stdio.h>

int main()
{int a,b,i,j,o;
scanf("%d%d",&a,&b);
int c[a];
for(i=0;i<a;i++){
scanf("%d",c[i]);
}
for(i=0;i<a;i++){
    for(j=i+1;j<a;j++){
        if(c[i]>c[j]){
            o=c[i];
            c[i]=c[j];
            c[j]=o;
        }}}
j=0;
for(i=0;i<a;i++){
    j=c[i]+j;
}
printf("%d",j);

return 0;
}