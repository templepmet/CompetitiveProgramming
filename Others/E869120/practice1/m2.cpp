#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n;
int fac[8];

int order(vector<int>& v) {
    set<int> st;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += (v[i] - 1 - distance(st.begin(), st.lower_bound(v[i]))) * fac[n - i - 1];
        st.insert(v[i]);
    }
    num++;
    return num;
}

int main() {
    int a, b;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i < n; ++i) {
        fac[i] = fac[i - 1] * i;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    a = order(v);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    b = order(v);
    cout << abs(a - b) << endl;

    return 0;
}