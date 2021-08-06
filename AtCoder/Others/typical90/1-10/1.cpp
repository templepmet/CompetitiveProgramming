#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n, l, k;
vector<int> a;

bool isok(int score) {
    int cnt = 0, st = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] - st >= score && l - a[i] >= score) {
            cnt++;
            st = a[i];
        }
    }
    if (cnt >= k) {
        return true;
    }
    return false;
}

int main() {
    cin >> n >> l >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int left = 1, right = l, mid; // left:ok, right:ng
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (isok(mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left << endl;

    return 0;
}