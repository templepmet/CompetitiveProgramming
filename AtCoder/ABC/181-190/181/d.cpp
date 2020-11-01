#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

bool f(string s) {
    // if (s.size() <= 3) {
    //     do {
    //         if (stoi(s) % 8 == 0)
    //             return true;
    //     } while (next_permutation(all(s)));
    //     return false;
    // }

    int num[10] = {};
    for (auto c : s) {
        num[c - '0']++;
    }

    for (int i = 1; i <= 999; i++) {
        int b[10] = {}, t = i, cnt = 0;
        while (t > 0) {
            b[t % 10]++;
            t /= 10;
            cnt++;
        }
        if (cnt != min((int)s.size(), 3)) {
            continue;
        }
        bool f = false;
        for (int j = 0; j < 10; ++j) {
            if (b[j] > num[j])
                f = true;
        }
        if (f) continue;
        if (i % 8 == 0) return true;
        // int k = (i / 2) % 100;
        // if (k % 4 == 0) {
        //     return true;
        // }
    }
    return false;
}

int main() {
    // for (int i = 1; i < 100; ++i) {
    //     if (i % 8 == 0 && !f(to_string(i)) || i % 8 != 0 && f(to_string(i))) {
    //         cout << i << endl;
    //     }
    // }
    // return 0;
    string s;
    cin >> s;

    if (f(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}