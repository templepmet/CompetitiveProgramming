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
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int main() {
    int n, q, x, y;
    int a[2000];
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (q--) {
        cin >> x >> y;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x)
                a[i] = y;
        }
    }
    cout << accumulate(a, a + n, 0) << endl;

    return 0;
}