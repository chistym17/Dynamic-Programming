#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int happiness[N][4];
int dp[N][4];
int func(int day,int current_task)
{
    if(day==1)return happiness[day][current_task];

    if(dp[day][current_task]!=-1)return dp[day][current_task];
    int max_profit=0;
    for(int last_task=1;last_task<=3;last_task++)
    {
        if(last_task==current_task)continue;
        int profit=func(day-1,last_task)+happiness[day][current_task];
        max_profit=max(max_profit,profit);

    }
    dp[day][current_task]=max_profit;
    return max_profit;


}
int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>happiness[i][j];

    }
}
memset(dp,-1,sizeof(dp));

int ans1=func(n,1);
int ans2=func(n,2);
int ans3=func(n,3);

cout<<max({ans1,ans2,ans3});



    return 0;
}