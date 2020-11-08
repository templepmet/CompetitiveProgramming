#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(0, 2 * a + 100 - b) << endl;

    return 0;
}