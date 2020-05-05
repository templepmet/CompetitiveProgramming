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

bool isPrime(int n) {
	if (n == 2)
		return true;

	if (n < 2 || n % 2 == 0)
		return false;

	for (int i = 3, k = sqrt(n); i <= k; i += 2) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int main() {
    int x;
    cin >> x;
    for (; ; ++x) {
        if (isPrime(x)) {
            cout << x << endl;
            break;
        }
    }

    return 0;
}