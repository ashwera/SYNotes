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

void solve() {
    int n; cin >> n;

    vector<pair<int,int>> jobs(n);
    for (auto& [p, d] : jobs) cin >> p >> d;

    sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){
        return a.first > b.first;
    });

    int maxD = 0;
    for (auto& [p, d] : jobs) maxD = max(maxD, d);

    vector<bool> slot(maxD + 1, false);

    int totalProfit = 0, jobsDone = 0;
    vector<int> scheduled;

    for (int i = 0; i < n; i++) {
        auto [profit, deadline] = jobs[i];

        for (int t = deadline; t >= 1; t--) {
            if (!slot[t]) {
                slot[t] = true;
                totalProfit += profit;
                jobsDone++;
                scheduled.push_back(i + 1);
                break;
            }
        }
    }

    cout << "Jobs scheduled: " << jobsDone << "\n";
    cout << "Max Profit: " << totalProfit << "\n";
    cout << "Scheduled job order (by sorted index): ";
    print(scheduled);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}