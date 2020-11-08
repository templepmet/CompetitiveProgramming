#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> p[26];
    for (int i = 0; i < s.size(); ++i) {
        p[s[i] - 'a'].push_back(i);
    }
    int suf = 0, loop = 0;
    for (int i = 0; i < t.size();) {
        char c = t[i] - 'a';
        if (p[c].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto it = lower_bound(p[c].begin(), p[c].end(), suf);
        if (it == p[c].end()) {
            suf = 0;
            loop++;
            continue;
        }
        suf = *it + 1;
        i++;
    }
    ll ans = (ll)s.size() * loop + suf;
    cout << ans << endl;

    return 0;
}