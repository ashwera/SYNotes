#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES"  << endl;
#define no cout << "NO" << endl;
#define input for(int &i:v) cin >> i;
#define vall v.begin(),v.end()

void print(const vector<int>& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}

int partition(vector<int>& v, int l, int r) {
    int pivot = v[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        if(v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    return i+1;
}

void quickSort(vector<int>& v, int l, int r) {
    if(l >= r) return;

    int p = partition(v, l, r);
    quickSort(v, l, p-1);
    quickSort(v, p+1, r);
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    input
    quickSort(v, 0, n-1);
    print(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}