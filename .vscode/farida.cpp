#include<bits/stdc++.h>

using namespace std;
const int N=1e4;
 int coin[N];
int calculate_coins(int n){
    if(n<=0)return 0;
    if(n==1)return 1;

    int ans1=n+calculate_coins(n-2);
    int ans2=(n-1)+calculate_coins(n-3);

    return max(ans1,ans2);

}
int main()
{
    int t;
    cin>>t;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    cout<<calculate_coins(n);


    return 0;
}