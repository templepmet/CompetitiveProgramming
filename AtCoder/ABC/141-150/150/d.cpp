#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int main() {
    int n, k;
    ll a, b, m, x = 1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        b = a;
        int cnt = 0;
        while (a % 2 == 0) {
            a /= 2;
            cnt++;
        }
        if (i == 0) {
            k = cnt;
        }
        else if (k != cnt) {
            cout << 0 << endl;
            return 0;
        }
        x = lcm(x, b / 2);
        if (x > m) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (int)ceil((double)(m / x) / 2) << endl;

    return 0;
}