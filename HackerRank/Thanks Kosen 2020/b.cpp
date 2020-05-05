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
    int d = 1, r = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            d++;
            r = 0;
            k = 0;
        }
        else if (s[i] == 'R') {
            r++;
        }
        else {
            k++;
        }
        if (r >= 2) {
            break;
        }
        if (k >= 2) {
            break;
        }
        if (d > 5) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}