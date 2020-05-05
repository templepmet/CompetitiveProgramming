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
    ll t, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        ll a, sum = 0, maxv = 0, maxi = -1;
        bool f = true;
        for (ll i = 0; i < n; ++i) {
            cin >> a;
            sum += a;
            if (f) {
                if (maxv < a) {
                    maxv = a;
                    maxi = i;
                }
                if (sum > s) {
                    f = false;
                }
            }
        }
        if (sum <= s)
            cout << 0 << endl;
        else
            cout << maxi + 1 << endl;
    }

    return 0;
}