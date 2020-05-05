#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), p(n), q(n), r;
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> q[i];

    int i = 0;
    do {
        if (a == p)
            r.push_back(i);
        if (a == q)
            r.push_back(i);
        i++;
    } while(next_permutation(a.begin(), a.end()));

    cout << abs(r[0] - r[1]) << endl;

    return 0;
}