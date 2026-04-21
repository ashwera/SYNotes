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

    vector<pair<int,int>> items(n);
    for (auto& [w, p] : items) cin >> w >> p;

    sort(items.begin(), items.end(), [](auto& a, auto& b){
        return (double)a.second / a.first > (double)b.second / b.first;
    });

    double totalProfit = 0;
    int remaining = W;

    for (auto& [w, p] : items) {
        if (remaining <= 0) break;
        if (w <= remaining) {
            totalProfit += p;
            remaining -= w;
        } else {
            totalProfit += (double)p * remaining / w;
            remaining = 0;
        }
    }

    cout << fixed << setprecision(2) << totalProfit << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}