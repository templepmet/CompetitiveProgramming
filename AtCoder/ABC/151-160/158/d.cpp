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
    string s;
    int n, q, f;
    char c;
    bool flip = false;
    cin >> s >> n;
    list<char> ans;
    for (auto t : s) {
        ans.push_back(t);
    }
    while (n--) {
        cin >> q;
        if (q == 1) {
            flip = !flip;
        }
        else {
            cin >> f >> c;
            if (f == 1) {
                if (flip) {
                    ans.push_back(c);
                }
                else {
                    ans.push_front(c);
                }
            }
            else {
                if (flip) {
                    ans.push_front(c);
                }
                else {
                    ans.push_back(c);
                }
            }
        }
    }

    if (flip) {
        for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
            cout << *i;
        }
    }
    else {
        for (auto i = ans.begin(); i != ans.end(); ++i) {
            cout << *i;
        }
    }
    cout << endl;

    return 0;
}