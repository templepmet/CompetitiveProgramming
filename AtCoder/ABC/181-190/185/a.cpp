#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int a[4];
    for(int i = 0; i < 4; ++i)
        cin >> a[i];
    cout << *min_element(a, a + 4) << endl;

    return 0;
}