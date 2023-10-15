#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
char mat[N][N];
int dp[N][N];
int main()
{

int n;
cin>>n;
memset(dp,0,sizeof(dp));
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>mat[i][j];

}

}
dp[0][0]=1;

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if( i==0 && j==0)continue;

if(mat[i][j]=='*')continue;

if(i>0)
dp[i][j]+=dp[i-1][j];


if(j>0)
dp[i][j]+=dp[i][j-1];

}
}

cout<<dp[n-1][n-1];



return 0;

}