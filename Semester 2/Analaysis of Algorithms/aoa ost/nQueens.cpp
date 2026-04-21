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

void printBoard(vector<int>& queens, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (queens[i] == j ? "Q" : ".");
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col) return false;
        if (abs(queens[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void solve(int row, int n, vector<int>& queens, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        printBoard(queens, n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solve(row + 1, n, queens, count);
            queens[row] = -1;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> queens(n, -1);
    int count = 0;
    solve(0, n, queens, count);

    cout << "Total solutions: " << count << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}