#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;

bool is_kakko(int t) {
    int c, k = 0;
    for (int i = 0; i < n; ++i) {
        c = t % 2;
        t /= 2;
        if (c == 1)
            k++;
        else
            k--;
        if (k < 0)
            return false;
    }
    if (k == 0)
        return true;
    return false;
}

int main() {
    cin >> n;
    for (int t = 0; t < (1 << n); ++t) {
        if (!is_kakko(t)) continue;
        for (int i = n - 1; i >= 0; --i) {
            if (t & (1 << i))
                cout << ')';
            else
                cout << '(';
        }
        cout << endl;
    }


    return 0;
}