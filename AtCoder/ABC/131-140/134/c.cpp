#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, a, maxa = 0, maxb = 0, maxi;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (maxa <= a) {
            maxi = i;
            int t = maxa;
            maxa = a;
            a = t;
        }
        chmax(maxb, a);
    }
    for (int i = 0; i < n; ++i) {
        if (i == maxi)
            cout << maxb << endl;
        else
            cout << maxa << endl;
    }

    return 0;
}