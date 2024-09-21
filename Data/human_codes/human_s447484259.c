#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    vector<int>v(t),a;
    for(int i = 0;i<t;i++)cin>>v[i];
    for(int i = 0;i<t-1;i++){
        int ans = 0,j = i;
        if(v[i]==v[i+1] ||v[i+1]>v[i]){
            ans = 1;
            //v[i]+=(v[i+1]-v[i]);
            while(v[i]==v[i+1]){
                ans++;
                i++;
                if(i==t)break;
            }
        }
        //for(int k = j;k<i;k++)a.push_back(0);
        a.push_back(ans);
    }
    for(auto i:a)cout<<i<<endl;
    for(int i = 0;i<t-(int)a.size();i++)cout<<0<<endl;
    
	return 0;
}
