#include <iostream>
#include <algorithm>

using namespace std;

int n, a[200000];

int main() {
    cin >> n;
    int cur = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == cur) {
            cur++;
        }
        else {
            ans++;
        }
    }
    cout << (ans == n ? -1 : ans) << endl;

    return 0;
}