#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long int ll;
ll n,a[10005],b[10005],c[10005];
ll dp[100005][3];

ll max(ll u,ll v);

void testcase();

long long int enjoy( ll i,ll choice);//here i represents level and choice represents one of the 3 choices

int main()
{
    testcase();
    return 0;
}

void testcase()
{
    ll i;
    ll ans1,ans2,ans3,ans;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
    }
    for(int i=0;i<10005;i++)
    {
        for(int j=0;j<3;j++)
            dp[i][j]=-1;
    }
   /* dp[n][0]=0;
    dp[n][1]=0;
    dp[n][2]=0;*/
    ans1=enjoy(0,0);
    ans2=enjoy(0,1);
    ans3=enjoy(0,2);
    if(ans1>=ans2&&ans1>=ans3)
        ans=ans1;
    else if(ans2>=ans3&&ans2>=ans1)
        ans=ans2;
    else
        ans=ans3;
    printf("%lld\n",ans);
}

long long int enjoy( ll i,ll choice)
{
    if(i>=n) {
        //printf("Chosen choice on level %d is :%lld and present choice:%d\n", i, dp[i][choice],choice);
        return 0;
    }
    if(dp[i][choice]!=-1)
        return dp[i][choice];
    else
    {
        if(choice==0)
            dp[i][choice]=a[i]+max(enjoy(i+1,(choice+1)%3),enjoy(i+1,(choice+2)%3));
        if(choice==1)
            dp[i][choice]=b[i]+max(enjoy(i+1,(choice+1)%3),enjoy(i+1,(choice+2)%3));
        if(choice==2)
            dp[i][choice]=c[i]+max(enjoy(i+1,(choice+1)%3),enjoy(i+1,(choice+2)%3));
    }
    //printf("Chosen choice on level %d is :%lld and present choice:%d\n", i, dp[i][choice],choice);
    return dp[i][choice];
}

ll max(ll u, ll v)
{
    if(u>=v)
        return u;
    else
        return v;
}

/* 3
10 40 70
20 50 80
30 60 90
 */
//210
/*1
100 10 1
Sample Output 2
100
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
Sample Output 3
Copy
46*/
