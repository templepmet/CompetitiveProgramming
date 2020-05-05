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
    int n, m, p;
    string s;
    cin >> n >> m;
    vector<int> wa(n + 1, 0), ac(n + 1, 0);
    while (m--) {
        cin >> p >> s;
        if (s == "WA") {
            if (ac[p] == 0)
                wa[p]++;
        }
        else {
            ac[p] = 1;
        } 
    }
    int wav = 0, acv = 0;
    for (int i = 1; i <= n; ++i) {
        if (ac[i]) {
            acv++;
            wav += wa[i];
        }
    }
    cout << acv << " " << wav << endl;

    return 0;
}