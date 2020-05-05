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
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a % 2 == 0 && (a % 3 != 0 && a % 5 != 0)) {
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;

    return 0;
}