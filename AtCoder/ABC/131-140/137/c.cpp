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

string sa[100000];

int main() {
    int n;
    ll cnt = 0, ans = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        sa[i] = s;
    }
    sort(sa, sa + n);
    for (int i = 0; i + 1 < n; ++i) {
        if (sa[i] == sa[i + 1]) {
            cnt++;
        }
        else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ans += cnt * (cnt + 1) / 2;
    cout << ans << endl;

    return 0;
}