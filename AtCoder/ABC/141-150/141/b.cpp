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
    string s;
    cin >> s;
    bool f = true;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] == 'L') {
            f = false;
        }
        if (i % 2 == 1 && s[i] == 'R') {
            f = false;
        }
    }
    cout << (f ? "Yes" : "No") << endl;

    return 0;
}