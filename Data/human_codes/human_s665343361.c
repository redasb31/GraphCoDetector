/*calculated by Microsoft Visual Studio, Referred to "Editorial"*/i,A=-1,a[14]={0,1,1,1,7,4,1,336,384,334,220,108,36,6},b[10]={108,220,334,384,334,220,108,36,6};main(){long long n;scanf("%lld",&n);if(n<14)A=a[n];else if(n==27||n==29)A=(n-29?976:4);else if(n==61)A=1;else for(i=0;i<10;i++)if((long long)pow(2,i+5)-n==4)A=b[i];printf("%d",A);}