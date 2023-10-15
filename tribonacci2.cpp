#include<bits/stdc++.h>

using namespace std;
int main()
{

int series[1000];

for(int i=1;i<=3;i++)
{
    series[i]=1;
}

int n;
cin>>n;
for(int i=4;i<=n;i++)
{
    int ans=series[i-1]+series[i-2]+series[i-3];
    series[i]=ans;

}

cout<<series[n];


    return 0;
}