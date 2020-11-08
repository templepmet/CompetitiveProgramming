#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s;
    int cnt[3] = {};
    cin >> s;
    int n = s.size(), sum = 0;
    for (auto c : s) {
        int v = c - '0';
        sum += v;
        cnt[v % 3]++;
    }
    if (sum % 3 == 0) {
        cout << 0 << endl;
    }
    else if (sum % 3 == 1) {
        if (cnt[1] > 0 && n > 1) {
            cout << 1 << endl;
        }
        else if (cnt[2] >= 2 && n > 2) {
            cout << 2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    else {
        if (cnt[2] > 0 && n > 1) {
            cout << 1 << endl;
        }
        else if (cnt[1] > 1 && n > 2) {
            cout << 2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}