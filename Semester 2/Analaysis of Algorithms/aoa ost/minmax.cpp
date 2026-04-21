#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> findMinMax(vector<int>& v, int l, int r) {
    if(l == r) return {v[l], v[l]};

    if(r == l + 1) {
        if(v[l] < v[r]) return {v[l], v[r]};
        else return {v[r], v[l]};
    }

    int mid = (l + r) / 2;

    auto left = findMinMax(v, l, mid);
    auto right = findMinMax(v, mid+1, r);

    int mn = min(left.first, right.first);
    int mx = max(left.second, right.second);

    return {mn, mx};
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;

    auto ans = findMinMax(v, 0, n-1);

    cout << "Min: " << ans.first << endl;
    cout << "Max: " << ans.second << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}