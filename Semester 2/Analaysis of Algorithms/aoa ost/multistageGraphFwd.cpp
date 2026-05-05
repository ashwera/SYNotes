void solve() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> cost(n, LLONG_MAX);
    vector<int> parent(n, -1);

    cost[0] = 0; // source

    for (int u = 0; u < n; u++) {
        if (cost[u] == LLONG_MAX) continue;

        for (auto &[v, w] : adj[u]) {
            if (cost[u] + w < cost[v]) {
                cost[v] = cost[u] + w;
                parent[v] = u;
            }
        }
    }

    cout << "Min Cost: " << cost[n-1] << "\n";

    // path
    vector<int> path;
    int cur = n - 1;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << "\n";
}
