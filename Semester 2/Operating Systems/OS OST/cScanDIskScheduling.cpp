#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head, disk_size;
    char dir;

    cout << "Enter number of requests and head: ";
    cin >> n >> head;

    cout << "Enter direction (L/R): ";
    cin >> dir;

    vector<int> req(n);
    cout << "Enter disk requests:\n";
    for(int i = 0; i < n; i++) cin >> req[i];

    cout << "Enter disk size: ";
    cin >> disk_size;

    sort(req.begin(), req.end());

    int totalSeek = 0;
    vector<int> seq;

    auto it = lower_bound(req.begin(), req.end(), head);

    if(dir == 'R') {
        // move right
        for(auto i = it; i != req.end(); i++) {
            totalSeek += abs(*i - head);
            head = *i;
            seq.push_back(head);
        }

        // go to end
        if(head != disk_size - 1) {
            totalSeek += abs((disk_size - 1) - head);
            head = disk_size - 1;
        }

        // jump to 0
        totalSeek += (disk_size - 1);
        head = 0;

        // serve left side
        for(auto i = req.begin(); i != it; i++) {
            totalSeek += abs(*i - head);
            head = *i;
            seq.push_back(head);
        }
    }
    else { // dir == 'L'
        // move left
        for(auto i = it; i != req.begin();) {
            --i;
            totalSeek += abs(*i - head);
            head = *i;
            seq.push_back(head);
        }

        // go to 0
        if(head != 0) {
            totalSeek += abs(head - 0);
            head = 0;
        }

        // jump to end
        totalSeek += (disk_size - 1);
        head = disk_size - 1;

        // serve right side
        for(auto i = it; i != req.end(); i++) {
            totalSeek += abs(*i - head);
            head = *i;
            seq.push_back(head);
        }
    }

    cout << "\nSeek Sequence: ";
    for(int x : seq) cout << x << " ";

    cout << "\nTotal Seek Time: " << totalSeek << endl;

    return 0;
}