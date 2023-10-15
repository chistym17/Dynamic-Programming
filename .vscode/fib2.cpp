#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int series[N];
int main()
{
    int n;
    cin>>n;
    series[0]=0;
    series[1]=1;
    for(int i=2;i<=n;i++)
    {
        series[i]=series[i-1]+series[i-2];

    }

    cout<<series[n];



    



    return 0;
}