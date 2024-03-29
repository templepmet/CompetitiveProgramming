#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    map<int, int> mp;
    mp[1] = 8;
    mp[2] = 4;
    mp[3] = 2;
    mp[4] = 2;

    for (auto [key, value] : mp) {
        cout << key << " " << value << endl;
    }

    auto it = max_element(mp.begin(), mp.end());
    cout << it->first << " " << it->second << endl;

    return 0;
}