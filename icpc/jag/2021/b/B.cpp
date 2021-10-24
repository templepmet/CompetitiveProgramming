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
// cat B | ./a > B_answer

int h, w;
int a[200][200], H[200], W[200];
double EPS = 1e-12;

double f1(double c){
    double res = 0;
    rep(i, h){
        res += H[i] * (i-c);
    }
    return fabs(res);
}

double f2(double c){
    double res = 0;
    rep(i, w){
        res += W[i] * (i-c);
    }
    return fabs(res);
}

signed main(){
    while(true){
        cin >> h >> w;
        if(h == 0)break;
        rep(i, h){
            string s;
            cin >> s;
            rep(j, w){
                a[i][j] = s[j]-'0';
            }
        }
        
        rep(i, h) H[i] = 0;
        rep(i, w) W[i] = 0;
        rep(i, h)rep(j, w) H[i] += a[i][j];
        rep(i, w)rep(j, w) W[j] += a[i][j];
        
        // PRINTF(a, 5, 5);
        // PRINTF(W, 10);
        
        double hl = 0, hr = h;
        while(hl+EPS < hr){
            double c1 = hl + (hr-hl)/3;
            double c2 = hr - (hr-hl)/3;
            if(f1(c1) < f1(c2)) hr = c2;
            else hl = c1;
        }
        
        double wl = 0, wr = w;
        while(wl+EPS < wr){
            double c1 = wl + (wr-wl)/3;
            double c2 = wr - (wr-wl)/3;
            // cout << fixed << setprecision(10) << f2(c1) << " " << f2(c2) << endl;
            if(f2(c1) < f2(c2)) wr = c2;
            else wl = c1;
        }
        
        cout << fixed << setprecision(16) << hl+1 << " " << wl+1 << endl;
    }
    return 0;
}