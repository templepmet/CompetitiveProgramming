#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    set<int> st;
    for (int i = 0; i < 10; ++i)
        st.insert(i);
    for (auto it = st.begin(), itend = st.end(); it != itend; ++it) {
        cout << *it;
        if (*it % 2 == 0)
            st.erase(it);
    }

    for (auto t : st) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}