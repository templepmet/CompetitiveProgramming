#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    if (mp.begin()->second == 3) {
        cout << "Won" << endl;
    }
    else {
        cout << "Lost" << endl;
    }

    return 0;
}