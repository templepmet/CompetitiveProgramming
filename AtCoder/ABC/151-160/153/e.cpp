#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int dp[10001];

int main() {
    int h, n, a, b;
    cin >> h >> n;
    fill(dp, dp + h + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        for (int j = 0; j <= h; ++j) {
            if (dp[j] < INF) {
                dp[min(j + a, h)] = min(dp[min(j + a, h)], dp[j] + b);
            }
        }
    }
    cout << dp[h] << endl;

    return 0;
}

// 単純なdp