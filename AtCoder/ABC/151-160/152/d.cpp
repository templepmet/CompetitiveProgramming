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

int main() {
    int n;
    ll ans = 0;
    string s, t;
    int k = 0, v;
    cin >> n;
    t = to_string(n);
    char nn = t[0];
    int nl = t.size();
    for (int i = 1; i <= n; ++i) {
        s = to_string(i);
        int l = s.size();
        if (s[l - 1] == '0')
            continue;

        if (s[0] == s[l - 1]) { // 1
            ans++;
        }
        if ((s[l - 1] - '0') * 10 + (s[0] - '0') <= n) // 2
            ans++;
        
        for (int j = 1; j <= 4; ++j) {
            if (2 + j < nl) {
                ans += pow(10, j);
            }
            else if (2 + j == nl) {
                if (s[l - 1] < nn) {
                    ans += pow(10, j);
                }
                else if (s[l - 1] == nn) {
                    ans += stoi(t.substr(1, j));
                    if (t[nl - 1] >= s[0])
                        ans++;
                }
            }
            else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}