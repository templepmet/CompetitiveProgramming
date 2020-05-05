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

int main() {
    int n, k, m, a, sum = 0;
    cin >> n >> k >> m;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        sum += a;
    }
    // for (int j = 0; j <= k; ++j) {
    //     if ((double)(sum + j) / n >= m) {
    //         cout << j << endl;
    //         return 0;
    //     }
    // }
    // cout << -1 << endl;

    int v = n * m - sum;
    if (v <= k)
        cout << max(v, 0) << endl;
    else
        cout << -1 << endl;

    return 0;
}