#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

random_device rnd;
mt19937 mt;
uniform_int_distribution<> rande8(0, (int)1e8);

int f() {
    int cnt = 0, v;
    set<int> st;
    while (1) {
        v = rande8(mt);
        if (st.find(v) != st.end()) {
            return cnt;
        }
        st.insert(v);
        cnt++;
    }
}

int main() {
    int n = 300;
    ll sum = 0;

    mt.seed(rnd());
    for (int i = 0; i < n; ++i) {
        sum += f();
    }
    cout << sum / n << endl;

    return 0;
}