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
    int n, m, s, c;
    int a[3];
    fill(a, a + 3, -1);
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n > 1 && m == 0) {
        cout << pow(10, n - 1) << endl;
        return 0;
    }
    while (m--) {
        cin >> s >> c;
        if (a[s - 1] >= 0 && a[s - 1] != c) {
            cout << -1 << endl;
            return 0;
        }
        a[s - 1] = c;
    }
    for (int i = (n == 1 ? 0 : pow(10, n - 1)); i < pow(10, n); ++i) {
        string v = to_string(i);
        for (int j = 0; j < n; ++j) {
            if (v[j] - '0' != a[j] && a[j] >= 0)
                break;
            if (j == n - 1) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}