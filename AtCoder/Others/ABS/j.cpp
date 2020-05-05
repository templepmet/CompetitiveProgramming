#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    string s, t[4] = { "dream", "dreamer", "erase", "eraser" };
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 4; ++i)
        reverse(t[i].begin(), t[i].end());
    int suf = 0;
    while (suf < s.size()) {
        for (int i = 0; i < 4; ++i) {
            if (s.find(t[i], suf) == suf) {
                suf += t[i].size();
                break;
            }
            if (i == 3) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}