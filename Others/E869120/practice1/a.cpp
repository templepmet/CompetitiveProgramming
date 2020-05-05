#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; ++i) {
        if (n % i == 0 && n / i <= 9) {
            cout << "Yes" << endl;
            return 0;
        } 
    }
    cout << "No" << endl;

    return 0;
}