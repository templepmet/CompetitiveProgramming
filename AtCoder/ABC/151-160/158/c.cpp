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
#include <numeric>
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
    int a, b;
    cin >> a >> b;
    // int x = a / 0.08, y = b / 0.1;
    // if (x > y)
    //     swap(x, y);
    for (int i = 1; i <= 10000; ++i) {
        if ((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}