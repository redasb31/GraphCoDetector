h[4],c[4],C,Y,a[4],U[]={50,10,5,1},f;F(y,j,s,i){for(i=!~j?y<1?s+=y/50+y%50/10+y%10/5+y%5,s>C|s==C&y>Y?C=s,Y=y,memcpy(a,c,16):0:0,-1:h[j];~i;i--)c[j]=i,F(y-i*U[j],j-1,s+i);}main(i,y){for(;scanf("%d%d%d%d%d",&y,h+3,h+2,h+1,h)*y;)for(C=Y=-1e9,F(y/10,3,0),f&&puts(""),i=4;i--;f=1)a[i]&&printf("%d0 %d\n",U[i],a[i]);}