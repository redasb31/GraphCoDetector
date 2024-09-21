#include <iostream>
#include "bits/stdc++.h"
#define ll long long int 
using namespace std;
int dfs(int pos,int n, bool flag,string s,int count,vector<vector<vector<int>>>& dp,int k){
        if(pos >= n) return(count == k);
        if(dp[pos][count][flag] != -1) return dp[pos][count][flag];
        int limit=9;
        if(flag ) limit = s[pos]-'0';
        int res=0;
        for(int i=0;i<=limit;i++){
            if(!flag || i < limit){
                if(i != 0) res+=dfs(pos+1,n,0,s,count+1,dp,k);
                else res+=dfs(pos+1,n,0,s,count,dp,k);
            }
            else{
               if(i != 0) res+=dfs(pos+1,n,1,s,count+1,dp,k);
                else res+=dfs(pos+1,n,1,s,count,dp,k);
            }
        }
        return dp[pos][count][flag]=res;
    }
int main()
{
        int n,k;
        cin >> n >>k;
        string s= to_string(n);
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(162,vector<int>(2,-1)));
        cout<<dfs(0,s.size(),1,s,0,dp,k)<<endl;
    return 0;
}