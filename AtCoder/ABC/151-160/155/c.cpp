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
    int n, maxv = 0;
    string s;
    map<string, int> mp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        mp[s]++;
        maxv = max(maxv, mp[s]);
    }
    vector<string> ans;
    for (auto t : mp) {
        if (t.second == maxv) {
            ans.push_back(t.first);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto t : ans) {
        cout << t << endl;
    }

    return 0;
}