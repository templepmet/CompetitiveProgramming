#include <bits/stdc++.h>
using namespace std;
// define
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (((a)%mod) * ((b)%mod)) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define dmt(x, y, z) make_tuple(x, y, z)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define fi first
#define se second
// debug
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p){
    os << "(" << p.first << "," << p.second << ")";return os;
}
template <typename T, typename U, typename V>
ostream &operator<<(ostream &os, const tuple<T, U, V> &t){
    os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
    for (auto it = v.begin();it != v.end();++it){
        if(it != v.begin())os << " ";os << *it;
    }return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp){
    for(auto x: mp)os << "(" << x.first << "," << x.second << ")" << endl;
    return os;
}
template<typename T, int SIZE>
int array_length(const T (&)[SIZE]){return SIZE;}
template<typename T, int N>
void PRINTF(const T (&a)[N], int s = N, int t = -1, bool f = true){
	if(t == -1){rep(i,s){if(i)cout << " ";cout << a[i];}}
	else repi(i,s,t){if(i!=s)cout << " ";cout << a[i];}
	if(f)cout << "\n";
}
template<typename T, int N1, int N2>
void PRINTF(const T (&a)[N1][N2], int h = N1, int w = N2){
    rep(i,h){rep(j,w){cout << a[i][j] << " \n"[j==w-1];}}
}
string substr(const string &str, int S1, int S2 = -1){
    if(S2 == -1)return str.substr(S1);
    return str.substr(S1, S2-S1);
}
// typedef
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef tuple<int, int, int> TT;
typedef pair<int, TT> PT;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;
// int sum = accumulate(a, a+n, 0LL);
// int mx = max_element(a, a+n);
// int mn = min_element(a, a+n);
// int cnt = count(a, a+n, k);
// cat D | ./a > D_answer

// bu ri syabu syabu ri bu
// 4 4 25
// a bcd ef ef bcd a
// 0 9 4
// s a t o r a r e p o t e n e t o p e r a r o t a s
// 0 0 0 0 0 0 0 0 0 0 0 0

// dp[i] = s[0]...s[i] と s[n-1-i]...s[n-1] を回文にするための最小値

using ll = long long;
class RollingHash {
		static const ll base1 = 1009;
		static const ll base2 = 2009;
		static const ll mod1 = 1000000007;
		static const ll mod2 = 1000000009;
		vector<ll> hash1, hash2, pow1, pow2;

public:
		RollingHash(const string &s) {
				int n = s.size();
				hash1.assign(n + 1, 0);
				hash2.assign(n + 1, 0);
				pow1.assign(n + 1, 1);
				pow2.assign(n + 1, 1);
				for (int i = 0; i < n; ++i) {
						hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
						hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
						pow1[i + 1] = (pow1[i] * base1) % mod1;
						pow2[i + 1] = (pow2[i] * base2) % mod2;
				}
		}

		// [l, r)
		pair<ll, ll> get(int l, int r) const {
				ll res1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
				ll res2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
				return make_pair(res1, res2);
		}

		pair<ll, ll> hash() const {
				return get(0, hash1.size() - 1);
		}
};

int dp[20010];

string strrev(string s){
    reverse(all(s));
    return s;
}

signed main(){
    while(true){
        string s;cin >> s;
        if(s == "#") break;
        int n = s.size();
        rep(i, n) dp[i] = -1;

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        
        RollingHash rh(s);

        repi(i, 1, n){
            int m = INF;
            bool f = true;
            for(int j = i-1; j >= 0; j--){
                // cout << s[j] << " " << s[n-1-j] << endl;
                // if(s[j] != s[n-1-j]) break;
                if(j != 0 && dp[j-1] == -1) continue;
                // PRINTF(dp, n);
                // cout << i << " " << substr(s, j, i) << " " << substr(s, n-i, n-j) << endl;
                // if(substr(s, j, i) == substr(s, n-i, n-j)){
                // if(rh.get(j, i) == rh.get(n - i, n - j) && substr(s, j, i) == substr(s, n-i, n-j)){
                if(rh.get(j, i) == rh.get(n - i, n - j)){
                    if(j == 0) {
                        if(i-j == 1) chmin(m, 0LL);
                        chmin(m, (i-j)*(i-j));
                        continue;
                    }
                    chmin(m, dp[j-1] + (i-j)*(i-j));
                    if(i-j == 1) chmin(m, dp[j-1]);
                }
            }
            dp[i-1] = m;
            if(m == INF) dp[i-1] = -1;
        }
        
        int ans = 0;
        // rep(i, (n-1)/2+1)if(dp[i] != -1) ans += dp[i];
        // cout << ans << endl;;
        cout << dp[(n-1)/2] << endl;
    }
    return 0;
}