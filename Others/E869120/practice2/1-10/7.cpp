#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

pair<int, int> p[3000];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x1 = p[i].first;
            int x2 = p[j].first;
            int y1 = p[i].second;
            int y2 = p[j].second;
            int dx = x1 - x2;
            int dy = y1 - y2;
            if (binary_search(p, p + n, make_pair(x1 + dy, y1 - dx)) && binary_search(p, p + n, make_pair(x2 + dy, y2 - dx)))
                ans = max(ans, dx * dx + dy * dy);
            if (binary_search(p, p + n, make_pair(x1 - dy, y1 + dx)) && binary_search(p, p + n, make_pair(x2 - dy, y2 + dx)))
                ans = max(ans, dx * dx + dy * dy);
        }
    }
    cout << ans << endl;

    return 0;
}