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
    int n, k, r, s, p, ans = 0;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    for (int i = 0; i < k; ++i) {
        if (t[i] == 'r')
            ans += p;
        if (t[i] == 's')
            ans += r;
        if (t[i] == 'p')
            ans += s;
        bool win = true;
        for (int j = i + k; j < n; j += k) {
            if (t[j] != t[j - k] || (t[j] == t[j - k] && win == false)) {
                if (t[j] == 'r')
                    ans += p;
                if (t[j] == 's')
                    ans += r;
                if (t[j] == 'p')
                    ans += s;
                win = true;
            }
            else {
                win = false;
            }
        }
    }
    cout << ans << endl;

    return 0;
}