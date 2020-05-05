#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n, m, sum, ans = 0;
int a[10];
vector<int> b[10], c[10];

int dp1[10001][1001];
int dp2[11][1001];

int main() {
    cin >> n >> m >> sum;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        sum = max(sum, a[i]);
    }
    int d, bt, ct;
    for (int i = 0; i < n; ++i) {
        cin >> d >> bt >> ct;
        d--;
        b[d].push_back(bt);
        c[d].push_back(ct);
    }

    fill(dp2[0], dp2[11], INF);
    dp2[0][0] = 0;
    for (int k = 0; k < m; ++k) {
        d = b[k].size();
        fill(dp1[0], dp1[d + 1], INF);
        dp1[0][0] = 0;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (dp1[i][j] < INF) {
                    dp1[i + 1][j] = min(dp1[i + 1][j], dp1[i][j]);
                    dp1[i + 1][min(j + c[k][i], sum)] = min(dp1[i + 1][min(j + c[k][i], sum)], dp1[i][j] + b[k][i]);
                }
            }
        }
        for (int i = 0; i <= sum; ++i) {
            if (dp2[k][i] < INF) {
                for (int j = a[k]; j <= sum; ++j) {
                    if (dp1[d][j] < INF) {
                        dp2[k + 1][min(i + j, sum)] = min(dp2[k + 1][min(i + j, sum)], dp2[k][i] + dp1[d][j]);
                    }   
                }
            }
        }
    }
    cout << dp2[m][sum] << endl;

    return 0;
}