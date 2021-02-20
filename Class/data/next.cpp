#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    string s;
    cin >> s;

    int m = s.size();
    vector<int> nxt(m);
    int j = -1;
    for (int i = 0; i < m; ++i) {
        nxt[i] = j;
        while ((j >= 0) && (s[i] != s[j]))
            j = nxt[j];
        j++;
    }

    for (int i = 0; i < m; ++i) {
        cout << nxt[i] << " ";
    }
    cout << endl;

    return 0;
}