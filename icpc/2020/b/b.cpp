#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int m, n, p, a, b;
    while (cin >> m >> n >> p && m > 0) {
        set<int> st;
        st.insert(p);
        while (n--) {
            cin >> a >> b;
            if (st.find(a) != st.end() || st.find(b) != st.end()) {
                st.insert(a);
                st.insert(b);
            }
        }
        cout << st.size() << endl;
    }

    return 0;
}