#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (auto &c : s) {
        c = 'A' + (c - 'A' + n) % 26;
    }
    cout << s << endl;

    return 0;
}