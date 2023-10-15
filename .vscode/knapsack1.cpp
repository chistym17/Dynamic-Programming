#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int value[N];
int weight[N];
int n,capacity;
int dp[N][N];

int max_profit(int n,int capacity)
{
if(n==0)return 0;

if(dp[n][capacity]!=-1)return dp[n][capacity];

if(capacity<weight[n])//corner case
{
    int ans=max_profit(n-1,capacity);
    dp[n][capacity]=ans;
    return ans;
}

int ans1=value[n]+max_profit(n-1,capacity-weight[n]);
int ans2=max_profit(n-1,capacity);
dp[n][capacity]=max(ans1,ans2);
return dp[n][capacity];

}

int main()
{
cin>>n>>capacity;
memset(dp,-1,sizeof(dp));



for(int i=1;i<=n;i++)
{
    cin>>value[i];
}


for(int i=1;i<=n;i++)
{
    cin>>weight[i];
}

cout<<max_profit(n,capacity);

    return 0;
}