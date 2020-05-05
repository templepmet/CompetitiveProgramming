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
    int n, k, cnt = 0;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1])
            cnt++;
    }
    cout << min(n - 1, cnt + 2 * k) << endl;

    return 0;
}