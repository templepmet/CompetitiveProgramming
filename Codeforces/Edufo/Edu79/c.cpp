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

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

pair<int, int> a[100000];
int b[100000];

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        sort(a, a + n);
        int maxk = -1, k;
        ll sum = 0;
        for (int i = 0; i < m; ++i) {
            k = a[lower_bound(a, a + n, make_pair(b[i], 0)) - a].second;
            if (maxk < k) {
                sum += (k - i) * 2;
                maxk = k;
            }
            sum++;
        }
        cout << sum << endl;
    }

    return 0;
}