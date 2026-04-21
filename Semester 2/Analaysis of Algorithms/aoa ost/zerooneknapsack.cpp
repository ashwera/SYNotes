#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define input for(int &i:v) cin >> i;
#define vall v.begin(),v.end()

void print(const vector<int>& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}

void solve() {
    int n, W;
    cin >> n >> W;

    vector<int> w(n), p(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> p[i];
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if (w[i-1] <= j){
                    dp[i][j] = max(dp[i][j], dp[i-1][j - w[i-1]] + p[i-1]);
            }
        }
    }

    cout << "Max Profit: " << dp[n][W] << "\n";

    vector<int> chosen;
    int j = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][j] != dp[i-1][j]) {
            chosen.push_back(i);
            j -= w[i-1];
        }
    }

    reverse(chosen.begin(), chosen.end());
    cout << "Items taken: ";
    print(chosen);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}