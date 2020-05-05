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
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    if (n <= k)
        cout << 0 << endl;
    else
        cout << accumulate(h.begin(), h.end() - k, 0LL) << endl;

    return 0;
}