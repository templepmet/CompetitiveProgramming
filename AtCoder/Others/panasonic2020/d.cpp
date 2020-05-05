#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

set<string> ans;
string s;

int n;
void dfs(int d, int m) {
    if (d == n) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i <= m; ++i) {
        s[d] = 'a' + i;
        dfs(d + 1, max(i + 1, m));
    }
}

int main() {
    cin >> n;
    s = string(n, 'a');
    dfs(0, 0);

    return 0;
}