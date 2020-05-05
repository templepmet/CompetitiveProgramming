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
    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i + l - 1 < n; ++i) {
            int a[26] = { 0 };
            for (int j = 0; j < l; ++j) {
                a[s[i + j] - 'a'] = 1;
            }
            if (count(a, a + 26, 1) == k)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

// O(n)でアルファベット頻度を累積和
// O(1)でi~jのアルファベットの数がわかる
// その数の種類がKかどうかの数→O(n^2)