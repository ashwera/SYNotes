#include <bits/stdc++.h>
using namespace std;

// code is not in syllabus: only for understanding + retention

vector<int> buildLPS(string p) {
    int m = p.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string t, string p) {
    int n = t.size();
    int m = p.size();

    vector<int> lps = buildLPS(p);

    int i = 0, j = 0;

    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } 
        else if (i < n && t[i] != p[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string t = "ababcababcabc";
    string p = "ababc";

    KMP(t, p);
}
