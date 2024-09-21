
#include <stdio.h>
#include <string.h>

int main(void)
{
    
    char S[100000];
    int SL=0;
    int cnt=0;
    int W=0;
    int B=0;
    int WW,BB;
    
    gets(S);
    SL=(int)strlen(S);
    
    
    
    while (1) {
       
        W=0;
        B=0;
        for (int i=0; i<SL; i++)
        {
            
            if(S[i]=='W') W++;
            if(S[i]=='B') B++;
            
        }
        if ((W==0)||(B==0)) {
            break;
        }
        
        
        
        
        if(cnt%2==1){
            if (S[SL-1]=='B') {
                S[SL]='W';
                for (int  i=SL-1; S[i]!='W';i-- ) {
                    S[i]='W';
                }
                
            }
           else if (S[0]=='B') {
                
                
                S[SL]=S[SL-1];
                for (int  i=SL-1; i==0;i-- ) {
                    S[i]=S[i-1];
                }
                S[0]='W';
                
            }

                              }
        else{
            
           if (S[0]=='W') {
                S[SL]=S[SL-1];
                for (int  i=SL-1; i==0;i-- ) {
                    S[i]=S[i-1];
                }
                S[0]='B';
                
            }

                       else if (S[SL-1]=='W') {
                S[SL]='B';
                for (int  i=SL-1; S[i]!='B';i-- ) {
                    S[i]='B';
                }
                
            }
         
            
            
        }
      
        
        SL=(int)strlen(S);
        
        cnt++;
    }
    
    
    printf("%d",cnt);
    
    return 0;
}