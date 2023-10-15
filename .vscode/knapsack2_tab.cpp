#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int value[N];
int weight[N];
int n,capacity;
int dp[N][N];

int main()
{
cin>>n>>capacity;
memset(dp,-1,sizeof(dp));

for(int i=1;i<=capacity;i++)
{
    dp[0][capacity]=0;
}


for(int i=1;i<=n;i++)
{
    cin>>value[i];
}


for(int i=1;i<=n;i++)
{
    cin>>weight[i];
}



for(int i=1;i<=n;i++)
{
    for(int j=0;j<=capacity;j++)
    {
        int ans1=value[i]+dp[i-1][j-weight[i]];
        int ans2=dp[i-1][j];
        dp[i][j]=max(ans1,ans2);

    }
}

cout<<dp[n][capacity];

    return 0;
}