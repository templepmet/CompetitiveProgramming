#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size(), i = 0;
    s += "R";
    vector<int> a(n, 0);
    while (i < n) {
        int cnt = 0;
        while (s[i] == 'R') {
            i++;
            cnt++;
        }
        a[i - 1] += (cnt + 1) / 2;
        a[i] += cnt / 2;
        
        cnt = 0;
        int j = i;
        while (s[j] == 'L') {
            j++;
            cnt++;
        }
        a[i] += (cnt + 1) / 2;
        a[i - 1] += cnt / 2;
        i = j;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}