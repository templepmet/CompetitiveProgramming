#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n;

void dfs(int d, int m, string s) {
    if (d == n) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i < m; ++i)
        dfs(d + 1, m, s + (char)('a' + i));
    dfs(d + 1, m + 1, s + (char)('a' + m));
}

int main() {
    cin >> n;
    dfs(0, 0, "");

    return 0;
}