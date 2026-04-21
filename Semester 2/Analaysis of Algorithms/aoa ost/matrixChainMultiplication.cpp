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

void printOrder(vector<vector<int>>& bracket, int i, int j) {
    if (i == j) { cout << "M" << i; return; }
    cout << "(";
    printOrder(bracket, i, bracket[i][j]);
    printOrder(bracket, bracket[i][j] + 1, j);
    cout << ")";
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) cin >> p[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> bracket(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e18;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Min multiplications: " << dp[1][n] << "\n";
    cout << "Optimal order: ";
    printOrder(bracket, 1, n);
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}