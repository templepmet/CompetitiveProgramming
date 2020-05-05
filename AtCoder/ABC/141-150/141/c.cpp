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

int p[100000];

int main() {
    int n, k, q, a;
    cin >> n >> k >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a;
        p[--a]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << (p[i] + k - q > 0 ? "Yes" : "No") << endl;
    }

    return 0;
}