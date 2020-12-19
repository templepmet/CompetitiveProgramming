#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d <= 1; d++) {  // for (T d = 0; d <= 0; d++) でも良い
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> x1(m + 1), x2(m + 1), y1(m + 1), y2(m + 1);
    x1[0] = x2[0] = 1;
    y1[0] = y2[0] = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> x1[i] >> y1[i];
        x2[i] = x1[i];
        y2[i] = y1[i];
    }
    x1.push_back(0);
    y1.push_back(0);
    x2.push_back(b + 1);
    y2.push_back(0);
    
    x1.push_back(0);
    y1.push_back(0);
    x2.push_back(0);
    y2.push_back(a + 1);
    
    x1.push_back(b + 1);
    y1.push_back(0);
    x2.push_back(b + 1);
    y2.push_back(a + 1);

    x1.push_back(0);
    y1.push_back(a + 1);
    x2.push_back(b + 1);
    y2.push_back(a + 1);

    vector<int> x = compress(x1, x2);
    vector<int> y = compress(y1, y2);
    int w = x.size();
    int h = y.size();
    vector<vector<int>> f(w, vector<int>(h));
    for (int i = 0; i <= m; ++i) {
        f[x1[i]][y1[i]] = 1;
    }
    f[0][0] = 2;
    for (int i = 0; i < h; ++i) {
        if (f[0][i] == 1) {
            break;
        }
        for (int j = 0; j < w; ++j) {
            if (f[j][i] == 1)
                break;
            f[j][i] = 2;
        }
    }
    for (int i = 0; i < w; ++i) {
        if (f[i][0] == 1)
            break;
        for (int j = 0; j < h; ++j) {
            if (f[i][j] == 1)
                break;
            f[i][j] = 2;
        }
    }

    ll ans = 0;
    for (int j = 0; j < w - 1; ++j) {
        for (int i = 0; i < h - 1; ++i) {
            if (f[j][i] == 2) {
                ans += (x[j + 1] - x[j]) * (y[i + 1] - y[i]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}