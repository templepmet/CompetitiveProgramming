#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll d = gcd(a, gcd(b, c));
	ll ans = a / d + b / d + c / d - 3;
	cout << ans << endl;

	return 0;
}