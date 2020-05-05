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

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (a < k) {
        k -= a;
        a = 0;
        if (b <= k) {
            b = 0;
        }
        else {
            b -= k;
        }
    }
    else {
        a -= k;
    }
    
    cout << a << " " << b << endl;

    return 0;
}