#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int h, w, c[26] = {};
    char f[100][100], visit[100][100] = {};
    vector<int> v;

    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> f[i][j];
            c[f[i][j] - 'a']++;
            if (visit[i][j])
                continue;

            int cnt = 1;
            if (h - i - 1 != i)
                cnt++;
            if (w - j - 1 != j)
                cnt++;
            if (cnt == 3)
                cnt++;
            
            visit[i][j] = 1;
            visit[h - i - 1][j] = 1;
            visit[i][w - j - 1] = 1;
            visit[h - i - 1][w - j - 1] = 1;
            
            v.push_back(cnt);
        }
    }
    sort(c, c + 26);
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); ++i) {
        int s = lower_bound(c, c + 26, v[i]) - c;
        if (s == 26) {
            cout << "No" << endl;
            return 0;
        }
        c[s] -= v[i];
        sort(c, c + 26);
    }
    cout << "Yes" << endl;

    return 0;
}