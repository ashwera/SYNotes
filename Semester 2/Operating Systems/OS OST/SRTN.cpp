#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter arrival time and burst time:\n";
    for(int i = 0; i < n; i++) {
        p[i].id = i;
        cin >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt; // remaining time
    }

    int completed = 0, time = 0;

    while(completed < n) {
        int idx = -1;
        int minRT = INT_MAX;

        // pick process with smallest remaining time
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(p[i].rt < minRT) {
                    minRT = p[i].rt;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++; // idle CPU
            continue;
        }

        // execute for 1 unit
        p[idx].rt--;
        time++;

        // if finished
        if(p[idx].rt == 0) {
            completed++;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(auto &x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }

    return 0;
}