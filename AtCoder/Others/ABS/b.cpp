#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a * b % 2 == 0 ? "Even" : "Odd") << endl;

    return 0;
}