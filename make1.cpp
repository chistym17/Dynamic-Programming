#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int inf=1e5;
int memo[N];
int main()
{
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    int x, y, z;
    x = y = z = inf;

    for(int i = 4; i <= n; i++)
    {  
        if(i % 2 == 0)
        {
            x = 1 + memo[i/2];
        }
        if(i % 3 == 0)
        {
            y = 1 + memo[i/3];
        }

        z = 1 + memo[i - 1];

        memo[i] = min({x, y, z});
        x = y = z = inf;
    }

    cout << memo[n];

    return 0;
}
