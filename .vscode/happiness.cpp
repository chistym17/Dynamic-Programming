#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int happiness[N][4];
int dp[N][4];
int fun(int day,int current_task)
{
    //handle base case
    if(day==1)return happiness[day][current_task];

    //check if ans is already calculated

    if(dp[day][current_task]!=-1)return dp[day][current_task];

    //recursive part
    int max_profit=0;
    for(int last_task=1;last_task<=3;last_task++)

    {   if(last_task==current_task)continue;

        int cand_profit=fun(day-1,last_task)+happiness[day][current_task];
        max_profit=max(cand_profit,max_profit);


    }
    dp[day][current_task]=max_profit;
    return max_profit;

}
int main()
{
int n;
cin>>n;

memset(dp,-1,sizeof(dp));

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=3;j++)
    {
       cin>> happiness[i][j];
    }
}

int ans1=fun(n,1);
int ans2=fun(n,2);
int ans3=fun(n,3);

int ans=max({ans1,ans2,ans3});

cout<<ans;

    return 0;
}