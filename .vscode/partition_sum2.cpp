#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int dp[N][N];
int nums[N];
int main()
{
    int n,target,sum=0;
    cin>>n;

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];
        sum+=nums[i];

    }
    target=sum/2;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            int ans1=dp[i-1][target];
            int ans2=dp[i-1][target-nums[j]];
            int ans=ans1||ans2;
            dp[i][j]=ans;
        }
    }

    cout<<dp[n][target];


    return 0;
}