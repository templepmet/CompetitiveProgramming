#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n;
    string s;
    map<string, int> mp;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[0] == '!') {
            mp[s.substr(1)] |= 2;
        }
        else {
            mp[s] |= 1;
        }
    }

    for (auto t : mp) {
        if (t.second == 3) {
            cout << t.first << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;

    return 0;
}