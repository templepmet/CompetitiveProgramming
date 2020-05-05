#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n, a[200000];
vector<int> w[100000];
int visit[100000];

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        a[i]--;
        w[a[i]].push_back(i);
    }
    int s = 0;
    for (int i = 0; i < 2 * n; ++i) {
        visit[a[s]] = 1;
        if (i % 2 == 0) { // edge
            if (s % 2 == 0)
                s++;
            else
                s--;
        }
        else { // warp
            if (w[a[s]][0] == s)
                s = w[a[s]][1];
            else
                s = w[a[s]][0];
        }
    }
    if (s == 0 && count(visit, visit + n, 1) == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}