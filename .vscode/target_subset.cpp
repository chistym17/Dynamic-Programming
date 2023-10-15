#include<bits/stdc++.h>
const int N=1e3;
int nums[N];
int dp[N][N];

using namespace std;
bool subset(int n,int target)
{
    if(n==0)
    {
        if(target==0)return 1;
        else return 0;
    }
    if(dp[n][target]!=-1)return dp[n][target];
    
    int ans2=subset(n-1,target);

    if(target<nums[n]){
    dp[n][target]=ans2;
    return ans2;
    }

    int ans1=subset(n-1,target-nums[n]);


    int ans=ans1 || ans2;
    dp[n][target]=ans;
    return ans;

}
int main()
{
    int n,w;
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>nums[i];

    }

    cout<<subset(n,w);




    return 0;
}