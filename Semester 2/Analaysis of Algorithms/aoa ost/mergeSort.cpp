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

void mergeVec(vector<int>& v, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);
    for(int i=0;i<n1;i++) L[i] = v[l+i];
    for(int i=0;i<n2;i++) R[i] = v[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }

    while(i<n1) v[k++] = L[i++];
    while(j<n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int l, int r) {
    if(l >= r) return;

    int mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    mergeVec(v, l, mid, r);
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    input

    mergeSort(v, 0, n-1);
    print(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}