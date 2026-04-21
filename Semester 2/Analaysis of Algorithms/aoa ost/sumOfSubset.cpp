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

void solve(vector<int>& arr, int idx, int target, int curr,vector<int>& subset, int& count) {
    if (curr == target) {
        count++;
        cout << "Solution " << count << ": { ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
        return;
    }
    if (idx == (int)arr.size() || curr > target) return;

    subset.push_back(arr[idx]);
    solve(arr, idx + 1, target, curr + arr[idx], subset, count);
    subset.pop_back();

    solve(arr, idx + 1, target, curr, subset, count);
}

void solve() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    vector<int> subset;
    int count = 0;
    solve(arr, 0, target, 0, subset, count);

    if (count == 0) cout << "No solution found\n";
    else cout << "Total solutions: " << count << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}