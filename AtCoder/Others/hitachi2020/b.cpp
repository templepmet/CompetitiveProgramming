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

int aa[100000];
int bb[100000];

int main() {
    int a, b, m, mina = 1e9, minb = 1e9, ans = 1e9;
    cin >> a >> b >> m;
    for (int i = 0; i < a; ++i) {
        cin >> aa[i];
        mina = min(mina, aa[i]);
    }
    for (int i = 0; i < b; ++i) {
        cin >> bb[i];
        minb = min(minb, bb[i]);
    }
    ans = min(ans, mina + minb);
    int x, y, c;
    while (m--) {
        cin >> x >> y >> c;
        ans = min(ans, aa[x - 1] + bb[y - 1] - c);
    }
    cout << max(0, ans) << endl;

    return 0;
}