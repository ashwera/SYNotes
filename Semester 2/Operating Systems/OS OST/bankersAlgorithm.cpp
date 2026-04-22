#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes and resources: ";
    cin >> n >> m;

    vector<int> available(m);
    cout << "Enter available resources:\n";
    for (int &i : available) cin >> i;
    // the ith resource has available[i] instances free

    vector<vector<int>> maxm(n, vector<int>(m));
    cout << "Enter max matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];

    // maximum resources each process may need
    // Process i
    // may need up to matrix[i][j] instances of resource j

    vector<vector<int>> alloc(n, vector<int>(m));
    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // allocation matrix: allocation[i][j] instances of resource j have been given to process i

    // Need matrix
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    vector<int> work = available;
    vector<bool> finish(n, false);
    vector<int> safeSeq;

    while (true) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            // /FOR THE ITH PROCESS
            if (!finish[i]) {
                bool possible = true;

                for (int j = 0; j < m; j++) {
                    // check the jth resource
                    if (need[i][j] > work[j]) {
                        // if it needs more than available, break
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    // if its possible, finish off and deallocate 
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    finish[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                }
            }
        }

        if (!found) break;
    }

    // Check safety
    bool safe = true;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            safe = false;
            break;
        }
    }

    if (safe) {
        cout << "\nSystem is in SAFE state\n";
        cout << "Safe sequence: ";
        for (int i : safeSeq)
            cout << "P" << i << " ";
        cout << endl;
    } else {
        cout << "\nSystem is NOT in safe state\n";
    }

    return 0;
}