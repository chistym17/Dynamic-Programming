#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e2;
int nums[N];
int first[N];
int last[N];
int dp[N];

int solve(int n, int arr[]) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return arr[1];
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = arr[n] + solve(n - 2, arr);

    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        if (i != n) {
            first[i] = nums[i];
        }

        if (i != 1) {
            last[i - 1] = nums[i];
        }
    }

    int ans1 = solve(n - 1, last);
    int ans2 = solve(n, first);
    cout << max(ans1, ans2);

    return 0;
}
