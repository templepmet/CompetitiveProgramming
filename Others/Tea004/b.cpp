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

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int main() {
    ll n1, d1, n2, d2, n, d;
    char p;
    cin >> n1 >> d1 >> p >> n2 >> d2;
    if (p == '+') {
        n = n1 * d2 + n2 * d1;
        d = d1 * d2;
    }
    if (p == '-') {
        n = n1 * d2 - n2 * d1;
        d = d1 * d2;
    }
    if (p == '/') {
        swap(n2, d2);
        p = '*';
    }   
    if (p == '*') {
        n = n1 * n2;
        d = d1 * d2;
    }
    ll div = gcd(abs(n), d);
    n /= div;
    d /= div;
    if (d == 1) {
        cout << n << endl;
    }
    else {
        cout << n << " " << d << endl;
    }

    return 0;
}