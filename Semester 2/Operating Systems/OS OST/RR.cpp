#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    cout << "Enter arrival time and burst time:\n";
    for(int i = 0; i < n; i++) {
        p[i].id = i;
        cin >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    queue<int> q;
    int time = 0, completed = 0;
    vector<bool> inQueue(n, false);

    while(completed < n) {
        // push newly arrived
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && !inQueue[i] && p[i].rt > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if(q.empty()) {
            time++;
            continue;
        }

        int i = q.front(); q.pop();

        int exec = min(tq, p[i].rt);
        p[i].rt -= exec;
        time += exec;

        // add newly arrived during execution
        for(int j = 0; j < n; j++) {
            if(p[j].at <= time && !inQueue[j] && p[j].rt > 0) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if(p[i].rt > 0) {
            q.push(i); //add the latest executed process back if remaining
        } else {
            completed++;
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(auto &x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }

    return 0;
}