#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, b = 0, h;
    bool f = true;
    cin >> n;
    while (n--) {
        cin >> h;
        if (h < b) {
            f = false;
        }
        if (h - 1 >= b)
            h--;
        b = h;
    }
    cout << (f ? "Yes" : "No") << endl;

    return 0;
}