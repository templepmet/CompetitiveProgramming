#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int num[40001];

int main() {
    int n, q, a[20], m[200];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; ++i)
        cin >> m[i];
    
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j))) {
                sum += a[j];
            }
        }
        num[sum] = 1;
    }
    
    for (int i = 0; i < q; ++i) {
        cout << (num[m[i]] ? "yes" : "no") << endl;
    }

    return 0;
}