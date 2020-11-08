#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int h, w, n, m;
vector<int> lighth[1501];
vector<int> lightw[1501];
vector<int> blockh[1501];
vector<int> blockw[1501];

bool islight(int y, int x) {
    int lblock, rblock, ablock, bblock;
    lblock = *(upper_bound(blockw[y].begin(), blockw[y].end(), x) - 1);
    rblock = *(lower_bound(blockw[y].begin(), blockw[y].end(), x));
    ablock = *(upper_bound(blockh[x].begin(), blockh[x].end(), y) - 1);
    bblock = *(lower_bound(blockh[x].begin(), blockh[x].end(), y));
    int ll, rl, al, bl;
    ll = lower_bound(lightw[y].begin(), lightw[y].end(), lblock + 1) - lightw[y].begin();
    rl = upper_bound(lightw[y].begin(), lightw[y].end(), rblock - 1) - lightw[y].begin() - 1;
    al = lower_bound(lighth[x].begin(), lighth[x].end(), ablock + 1) - lighth[x].begin();
    bl = upper_bound(lighth[x].begin(), lighth[x].end(), bblock - 1) - lighth[x].begin() - 1;
    if (ll <= rl || al <= bl)
        return true;
    return false;
}

int main() {
    cin >> h >> w >> n >> m;
    for (int i = 1; i <= w; ++i) {
        blockh[i].push_back(0);
        blockh[i].push_back(h + 1);
    }
    for (int i = 1; i <= h; ++i) {
        blockw[i].push_back(0);
        blockw[i].push_back(w + 1);
    }
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        lighth[b].push_back(a);
        lightw[a].push_back(b);
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        blockh[b].push_back(a);
        blockw[a].push_back(b);
    }

    for (int i = 0; i < 1501; ++i) {
        sort(lighth[i].begin(), lighth[i].end());
        sort(lightw[i].begin(), lightw[i].end());
        sort(blockh[i].begin(), blockh[i].end());
        sort(blockw[i].begin(), blockw[i].end());
    }

    int cnt = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (islight(i, j))
                cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}