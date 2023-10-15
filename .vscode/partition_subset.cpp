#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int dp[N][N];
int nums[N];

bool partion_subset(int n,int target)
{
    if(n==0)
    {
        if(target==0)return 1;
        else return 0;
    }

    if(dp[n][target]!=-1)return dp[n][target];
    
    int ans1=partion_subset(n-1,target);
    if(target<nums[n])
    {
        dp[n][target]=ans1;
        return ans1;

    }

    int ans2=partion_subset(n-1,target-nums[n]);

    dp[n][target]=ans1 || ans2;
    return dp[n][target];

}


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

    cout<<partion_subset(n,sum/2);



    return 0;
}

