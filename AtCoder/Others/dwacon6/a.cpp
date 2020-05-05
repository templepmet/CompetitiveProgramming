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
    int n, t[50];
    string s[50], x;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> t[i];
    cin >> x;
    bool flag = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == x) {
            flag = true;
            continue;
        }
        if (flag)
            sum += t[i];
    }
    cout << sum << endl;

    return 0;
}