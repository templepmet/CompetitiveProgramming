#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

string s = "";
int n, m, k;

int f[200][200] = { 0 };
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
string d = "RULD";

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || f[ny][nx])
            continue;
        s += d[i];
        f[ny][nx] = 1;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        s += 'U';
    for (int i = 0; i < m; ++i)
        s += 'L';
    f[0][0] = 1;
    dfs(0, 0);

    cout << s.size() << endl << s << endl;

    return 0;
}