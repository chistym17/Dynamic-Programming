#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int dp[N];

int squares(int n)
{
if(n==0)return 0;
if(dp[n]!=-1)return dp[n];

int ans=n;
for(int i=1;i*i<=n;i++)
{  
    ans=min(ans,1+squares(n-i*i));
    
}
dp[n]=ans;
return ans;


}

int main()
{
int n;
cin>>n;

memset(dp,-1,sizeof(dp));

cout<<squares(n);


    return 0;
}