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
    int n, b[101], sum = 0;
    cin >> n;
    b[0] = b[n] = INF;
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        sum += min(b[i - 1], b[i]);
    }
    cout << sum << endl;

    return 0;
}