#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int nums[N];
int dp[N];
int solve(int n)
{
if(n==0)return 0;
if(n==1)return 1;
if(dp[n]!=-1)return dp[n];

int ans1,ans2,ans;

ans1=nums[n]+solve(n-2);
return ans1;


ans2=nums[n-1]+solve(n-3);




ans=max(ans1,ans2);
dp[n]=ans;
return ans;


}


int main()
{
int n;
cin>>n;

for(int i=1;i<=n;i++)
{
cin>>nums[i];
}
cout<<solve(n);

    return 0;
}
