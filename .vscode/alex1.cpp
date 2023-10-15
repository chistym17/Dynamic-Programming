#include<bits/stdc++.h>

using namespace std;
const int N=1e4;
int sequence[N];
int calculate(int n)
{
    if(n<=0)return 0;

    int ans1=sequence[n]+calculate(n-2);
    int ans2=calculate(n-1);

    return max(ans1,ans2);
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>sequence[i];
    }

    cout<<calculate(n-1);




    return 0;
}