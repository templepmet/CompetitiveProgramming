#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

bool is_kaibun(string s) {
    // cout << s << endl;
    string t = s;
    reverse(t.begin(), t.end());
    if (t == s)
        return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    if (!is_kaibun(s)) {
        cout << "No" << endl;
    }
    else if (!is_kaibun(s.substr(0, (s.size() - 1) / 2))) {
        cout << "No" << endl;
    }
    else if (!is_kaibun(s.substr((s.size() + 3) / 2 - 1, 100))) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}