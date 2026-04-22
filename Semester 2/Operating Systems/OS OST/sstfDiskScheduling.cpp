#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int n, head;
	cout << "Enter number of requests: ";
	cin >> n;

	vector<int> req(n);
	cout << "Enter requests: ";
	for (int i = 0; i < n; i++) {
		cin >> req[i];
	}

	cout << "Enter initial head position: ";
	cin >> head;

	vector<bool> visited(n, false);
	int totalSeek = 0;

	cout << "\nSeek Sequence: ";
	for (int i = 0; i < n; i++) {
		int idx = -1;
		int minDist = INT_MAX;

		// find index of request not yet processed
		// and such that its dist is least 
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				int dist = abs(req[j] - head);
				if (dist < minDist) {
					minDist = dist;
					idx = j;
				}
			}
		}

		totalSeek += minDist;
		head = req[idx];
		visited[idx] = true;
		cout << head << " ";
	}

	cout << "\nTotal Seek Time: " << totalSeek << endl;
	return 0;
}