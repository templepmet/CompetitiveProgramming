#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    string s;
    cin >> s;
    cout << count(s.begin(), s.end(), '1') << endl;

    return 0;
}