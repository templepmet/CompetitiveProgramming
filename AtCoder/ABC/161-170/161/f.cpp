#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

set<ll> st;

int main() {
    ll n, m;
    cin >> n;
    m = n;
    st.insert(n);
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            ll t = n;
            while (t % i == 0)
                t /= i;
            if(t % i == 1)
                st.insert(i);
            t = n;
            while (t % (m / i) == 0)
                t /= (m / i);
            if (t % (m / i) == 1)
                st.insert(m / i);
        }
    }
    m = n - 1;
    if (n % m != 0)
        st.insert(m);
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            if (n % i != 0) {
                st.insert(i);
            }
            if (n % (m / i) != 0) {
                st.insert(m / i);
            }
        }
    }
    
    cout << st.size() << endl;

    return 0;
}