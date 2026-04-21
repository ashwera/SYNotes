#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES"  << endl;
#define no cout << "NO" << endl;

const int INF = 1e18;

void dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); 
    }

    int src; cin >> src;

    dijkstra(n, adj, src);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}