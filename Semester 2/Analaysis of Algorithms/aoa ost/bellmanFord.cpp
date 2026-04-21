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

    vector<tuple<int,int,int>> edges(e);
    for (auto& [u, v, w] : edges) cin >> u >> v >> w;

    int src;
    cin >> src;

    const int INF = 1e18;
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }

    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    cout << "Distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INF) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }

    cout << "\nPaths from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (i == src) continue;
        cout << "To " << i << ": ";
        if (dist[i] == INF) { cout << "No path\n"; continue; }
        vector<int> path;
        for (int cur = i; cur != -1; cur = prev[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());
        for (int j = 0; j < (int)path.size(); j++) {
            cout << path[j];
            if (j + 1 < (int)path.size()) cout << " -> ";
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}