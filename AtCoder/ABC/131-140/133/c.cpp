#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll l, r;
    cin >> l >> r;
    set<ll> st;
    int m = min(r - l + 1, 2019LL);
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            st.insert(((l + i) * (l + j)) % 2019);
        }
    }

    cout << *st.begin() << endl;

    return 0;
}