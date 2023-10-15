#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
int sequence[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int dp[N];
    dp[0] = sequence[0];
    dp[1] = max(sequence[0], sequence[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(sequence[i] + dp[i - 2], dp[i - 1]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}
