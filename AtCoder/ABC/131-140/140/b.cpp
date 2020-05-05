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
    int n, a[20], b[20], c[20], sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i) {
        sum += b[a[i] - 1];
        if (i > 0 && a[i] - a[i - 1] == 1)
            sum += c[a[i - 1] - 1];
    }
    cout << sum << endl;

    return 0;
}