#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, x[10][10], d, ans = 0;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> x[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < d; ++k) {
                sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]); 
            }
            int v = sqrt(sum);
            if (sum % v == 0 && v == sum / v)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}