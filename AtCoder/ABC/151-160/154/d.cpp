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

int main() {
    int n, k, sum = 0, m = 0;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
        if (i >= k) {
            sum -= p[i - k];
        }
        m = max(m, sum);
    }
    cout << fixed << setprecision(10);
    cout << (m + k) / 2.0 << endl;

    return 0;
}