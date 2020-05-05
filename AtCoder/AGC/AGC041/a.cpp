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
    ll n, a , b, c;
    cin >> n >> a >> b;
    c = min(a - 1 + (b - (a - 1)) / 2, n - b + (n - (a + (n - b))) / 2 + (n - (a + (n - b))) % 2);
    c = min(c, min(b - 1, n - a));
    if ((b - a) % 2 == 0)
        cout << min((b - a) / 2, c) << endl;
    else
        cout << c << endl;

    return 0;
}

// 1000000000000000000
// 999999999999999999