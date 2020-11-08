#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, p, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        if (p != i + 1) {
            cnt++;
        }
    }
    cout << (cnt > 2 ? "NO" : "YES") << endl;

    return 0;
}