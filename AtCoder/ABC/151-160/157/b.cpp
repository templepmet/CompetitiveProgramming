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

void yes() {
    cout << "Yes" << endl;
    exit(0);
}

int main() {
    int a[3][3], b[3][3] = { 0 };
    int n, v;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> n;
    while (n--) {
        cin >> v;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] == v)
                    b[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (b[i][0] && b[i][1] && b[i][2])
            yes();
        if (b[0][i] && b[1][i] && b[2][i])
            yes();
    }
    if (b[0][0] && b[1][1] && b[2][2])
        yes();
    if (b[0][2] && b[1][1] && b[2][0])
        yes();

    cout << "No" << endl;

    return 0;
}