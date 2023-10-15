#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int dp[N][N];
int nums[N];

int target_sum(int n,int target)
{
    if(n==0)
    {
        if(target==0)return 1;
        else return 0;
    }

    if(dp[n][target]!=-1)return dp[n][target];

    int ans=target_sum(n-1,target+nums[n])+target_sum(n-1,target-nums[n]);
    dp[n][target]=ans; ans;n()s