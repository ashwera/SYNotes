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
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> cost(n, INT_MAX);
    vector<int> next(n, -1);
    cost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (auto& [v, w] : adj[i]) {
            if (cost[v] != INT_MAX && w + cost[v] < cost[i]) {
                cost[i] = w + cost[v];
                next[i] = v;
            }
        }
    }

    cout << "Min Cost: " << cost[0] << "\n";
    cout << "Path: ";
    int cur = 0;
    while (cur != -1) {
        cout << cur;
        if (next[cur] != -1) cout << " -> ";
        cur = next[cur];
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}