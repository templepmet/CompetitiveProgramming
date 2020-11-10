#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[200001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        if (a[i]) {
            ans.push_back(i);
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    a[j] = !a[j];
                    if (j != i / j)
                        a[i / j] = !a[i / j];
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v << " ";
    }

    return 0;
}