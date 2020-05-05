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
    int n, m, a;
    ll sum = 0;
    cin >> n >> m;
    priority_queue<double> q;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        q.push(a);
    }
    while (m--) {
        double t = q.top();
        q.pop();
        q.push(t / 2);
    }
    for (int i = 0; i < n; ++i) {
        sum += (int)q.top();
        q.pop();
    }
    cout << sum << endl;

    return 0;
}