#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int dp[N];
int coins[N];

int main() {
   
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        dp[0] = 0;
        dp[1] = coins[0];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(coins[i - 1] + dp[i - 2], dp[i - 1]);
        }

        cout << dp[n];
    

    return 0;
}
