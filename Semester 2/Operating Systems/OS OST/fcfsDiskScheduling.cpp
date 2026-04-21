#include <bits/stdc++.h>
using namespace std;

signed main() {
    cout << "Enter number of processes and head \n";
    int n, head;
    cin >> n >> head;
    vector<int> req(n);
    cout << "Enter disk requests\n";
    for(int i = 0; i < n; i++) cin >> req[i];
    int totalSeek = 0;

    for(int i = 0; i < n; i++) {
        totalSeek += abs(req[i] - head);
        head = req[i];
    }

    cout << "Total Seek Time: " << totalSeek << endl;
    cout << "Seek Sequence: ";
    for(int i = 0; i < n; i++) {
        cout << req[i] << " ";
    }
}