#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, x;
    char c;
    vector<int> a, b;
    cin >> n;
    while (n--) {
        cin >> x >> c;
        if (c == 'R')
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (auto t :a) {
        cout << t << endl;
    }
    for (auto t : b) {
        cout << t << endl;
    }

    return 0;
}