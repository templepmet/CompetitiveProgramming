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
    int n;
    double v, u;
    priority_queue<double, vector<double>, greater<double>> q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        q.push(v);
    }
    for (int i = 0; i < n - 1; ++i) {
        v = q.top();
        q.pop();
        u = q.top();
        q.pop();
        q.push((u + v) / 2);
    }
    cout << fixed << setprecision(10) << q.top() << endl;

    return 0;
}