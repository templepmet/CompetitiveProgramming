#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

/*
    a[i]より初めて小さいj(>i)を格納した配列を返す O(n)
*/
template<class T>
vector<int> first_exceeder(vector<T> &a) {
    int n = a.size();
    vector<int> ex(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty()) {
            int top = st.top();
            if (a[top] > a[i]) { // 初めて小さい
                ex[top] = i;
                st.pop();
                continue;
            }
            break;
        }
        st.push(i);
    }
    while (!st.empty()) {
        ex[st.top()] = n;
        st.pop();
    }
    return ex;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto rev = a;
    reverse(rev.begin(), rev.end());
    auto r = first_exceeder(a);
    auto l = first_exceeder(rev);
    reverse(l.begin(), l.end());
    for (int i = 0; i < n; ++i) {
        l[i] = n - l[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        chmax(ans, a[i] * ((r[i] - i) + (i - l[i])));
    }
    cout << ans << endl;

    return 0;
}