#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int memo[N];

int calculate(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(memo[n]!=-1)return memo[n];

    memo[n]=calculate(n-1)+calculate(n-2);
    
    return memo[n];
}

int main()
{
    int n;
    cin>>n;
    memset(memo,-1,sizeof(memo));

    cout<<calculate(n);

    return 0;
}