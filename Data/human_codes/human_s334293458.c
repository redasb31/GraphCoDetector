int main(void)
{
    int i,a1,b1,c1,A,B,C,K,S,N;
    
    N = 10^18;
    
    scanf("%d %d %d %d",&A,&B,&C,&K);
    
    for(i=0;i<K;i++)
    {
        a1 = A;
        b1 = B;
        c1 = C;
        A = b1 + c1;
        B = a1 + c1;
        C = a1 + b1;
    }
    
    S = A - B;
    
    
    if(S*S > N*N)
    {
        printf("Unfair");
    }
    
    else
    {
        printf("%d\n",S);
    }
    
   
    
    
    return 0;
}
