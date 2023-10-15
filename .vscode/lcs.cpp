#include<bits/stdc++.h>
using namespace std;

int lcs(string s, string t, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + lcs(s, t, i - 1, j - 1, dp);
    else
        dp[i][j] = max(lcs(s, t, i - 1, j, dp),
                        lcs(s, t, i, j - 1, dp));

    return dp[i][j];
}

string lcs_string(string s, string t) {
    int n = s.length();
    int m = t.length();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    int length = lcs(s, t, n, m, memo);

    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs.push_back(s[i - 1]);
            i--;
            j--;
        } else if (memo[i - 1][j] > memo[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s, t;
    cin >> s >> t;

    string ans = lcs_string(s, t);
    cout << ans << endl;

    return 0;
}
