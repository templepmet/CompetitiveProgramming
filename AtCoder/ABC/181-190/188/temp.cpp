#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    set<P> st;
    st.emplace(5, 8);
    st.emplace(1, 4);
    st.emplace(9, 10);
    auto it = st.begin();
    cout << it->first << " " << it->second << endl;    

    return 0;
}