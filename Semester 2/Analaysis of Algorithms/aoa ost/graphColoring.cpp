#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;

bool isSafe(int v, int c) {
    for (int u : adj[v]) {
        if (color[u] == c) return false;
    }
    return true;
}

bool solve(int v) {
    if (v == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (solve(v + 1)) return true;

            color[v] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    color.assign(n, 0);

    int e;
    cin >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (solve(0)) {
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    } else {
        cout << "No solution\n";
    }
}
