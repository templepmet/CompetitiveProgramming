#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    auto b = a, c = a;
    for (int i = 0; i < h; ++i) {
        int sum = 0;
        for (int j = 0; j < w; ++j) {
            sum += b[i][j];
        }
        for (int j = 0; j < w; ++j) {
            b[i][j] = sum;
        }
    }
    for (int j = 0; j < w; ++j) {
        int sum = 0;
        for (int i = 0; i < h; ++i) {
            sum += c[i][j];
        }
        for (int i = 0; i < h; ++i) {
            c[i][j] = sum;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j > 0) cout << ' ';
            cout << b[i][j] + c[i][j] - a[i][j];
        }
        cout << endl;
    }

    return 0;
}