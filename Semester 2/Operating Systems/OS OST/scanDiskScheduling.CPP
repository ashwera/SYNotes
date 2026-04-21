#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, head, disk_size, direction;
	cout << "Enter number of requests: ";
	cin >> n;

	vector<int> requests(n);
	cout << "Enter the requests:\n";
	for (int i = 0; i < n; i++) {
		cin >> requests[i];
	}

	cout << "Enter initial head position: ";
	cin >> head;
	cout << "Enter disk size: ";
	cin >> disk_size;
	cout << "Enter direction (0 for left, 1 for right): ";
	cin >> direction;

	vector<int> left, right;
	for (int i = 0; i < n; i++) {
		if (requests[i] < head) {
			left.push_back(requests[i]);
		} else {
			right.push_back(requests[i]);
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int seek_count = 0;
	vector<int> seek_sequence;

	if (direction == 1) {
		for (int i = 0; i < right.size(); i++) {
			seek_sequence.push_back(right[i]);
			seek_count += abs(head - right[i]);
			head = right[i];
		}

		for (int i = left.size() - 1; i >= 0; i--) {
			seek_sequence.push_back(left[i]);
			seek_count += abs(head - left[i]);
			head = left[i];
		}
	} else {
		for (int i = left.size() - 1; i >= 0; i--) {
			seek_sequence.push_back(left[i]);
			seek_count += abs(head - left[i]);
			head = left[i];
		}

		for (int i = 0; i < right.size(); i++) {
			seek_sequence.push_back(right[i]);
			seek_count += abs(head - right[i]);
			head = right[i];
		}
	}

	cout << "\nSeek Sequence: ";
	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << " ";
	}
	cout << "\nTotal Seek Time: " << seek_count << endl;
	return 0;
}