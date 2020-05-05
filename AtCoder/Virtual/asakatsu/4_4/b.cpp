#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int a[100000];
map<int, int> c;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[a[i]]++;
        c[a[i] - 1]++;
        c[a[i] + 1]++;
    }

    int maxv = 0, maxc = 0;
    for (auto t : c) {
        if (maxc < t.second) {
            maxc = t.second;
            maxv = t.first;
        }
    }

    cout << maxc << endl;

    return 0;
}