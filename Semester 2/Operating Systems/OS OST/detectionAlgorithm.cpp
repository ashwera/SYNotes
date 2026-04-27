#include <bits/stdc++.h>
using namespace std;

// detect deadlocked processes
vector<int> detectDeadlock(vector<vector<int>> alloc, vector<vector<int>> request, vector<int> avail) {

    int n = alloc.size(), m = avail.size();

    vector<bool> finish(n,false);
    vector<int> work = avail;

    while(true) {
        bool found = false;

        for(int i=0;i<n;i++) {
            if(!finish[i]) {
                bool ok = true;

                for(int j=0;j<m;j++)
                    if(request[i][j] > work[j]) ok = false;

                if(ok) {
                    // simulate completion
                    for(int j=0;j<m;j++)
                        work[j] += alloc[i][j];

                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) break;
    }

    vector<int> dead;
    for(int i=0;i<n;i++)
        if(!finish[i]) dead.push_back(i);

    return dead;
}

int main() {
    int n = 3, m = 3;

    // allocation matrix
    vector<vector<int>> alloc = {
        {0,1,0},
        {2,0,0},
        {3,0,2}
    };

    // request matrix
    vector<vector<int>> request = {
        {0,0,0},
        {2,0,2},
        {0,0,1}
    };

    // available resources
    vector<int> avail = {0,0,0};

    vector<int> ans = detectDeadlock(alloc, request, avail);

    if(ans.empty()) {
        cout << "No deadlock\n";
    } else {
        cout << "Deadlocked processes: ";
        for(int x : ans) cout << x << " ";
    }

    return 0;
}