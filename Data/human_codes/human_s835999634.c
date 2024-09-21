#include <stdio.h>

int main(void){
    
    int n; scanf("%d",&n);
    int ans=0;
    char s[n]; scanf("%s",&s);

    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            if (s[i]==s[j]) continue;
            for (int k=j+1; k<n; k++){
                if ((s[i]==s[k]) || (s[j]==s[k]) ||(j-i==k-j)) continue;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}