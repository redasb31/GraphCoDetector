c,t,d[4010][4010];char s[4010];i,j;main(){for(**d=scanf("%s",s);s[i/2];i++)for(j=c+=s[i]?t++,s[i]-48:0;j>i+c-2*t&&~j;j--)d[i+1][j]=(d[i][j]+d[i][j-1])%998244353;printf("%d",d[i][c]);}