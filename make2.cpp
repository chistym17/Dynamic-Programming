#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int inf=1e5;
int memo[N];

int calculate(int n) {
    if (n == 1)
        return 0;
    if (memo[n] != -1)
        return memo[n];

    int x = inf, y = inf, z = inf;
    if (n % 2 == 0)
        x = 1 + calculate(n / 2);
    if (n % 3 == 0)
        y = 1 + calculate(n / 3);
    z = 1 + calculate(n - 1);

    memo[n] = min({x, y, z});
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));

    int minSteps = calculate(n);

    cout << minSteps;

    return 0;
}
