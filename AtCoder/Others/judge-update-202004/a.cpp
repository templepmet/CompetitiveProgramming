#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int s, l, r;
    cin >> s >> l >> r;
    if (s < l) {
        cout << l << endl;
    }
    else if (s > r) {
        cout << r << endl;
    }
    else {
        cout << s << endl;
    }

    return 0;
}