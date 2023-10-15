#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
char mat[N][N];
int dp[N][N];

int paths(int n,int m)
{
if(n==0 && m==0)return 1;

if(dp[n][m]!=-1)return dp[n][m];


if(mat[n][m]=='*')return 0;

int ans=0;
if(n>0)
ans+=paths(n-1,m);
if(m>0)
ans+=paths(n,m-1);

dp[n][m]=ans;
return ans;


}


int main()
{
int n;
cin>>n;
memset(dp,-1,sizeof(dp));

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>mat[i][j];

}

}

cout<<paths(n-1,n-1);
return 0;


    return 0;
}
