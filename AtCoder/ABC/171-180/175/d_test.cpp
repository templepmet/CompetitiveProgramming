#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
ll k;
vector<ll> p, c;

ll solve1() { // high speed
    vector<ll> w(n + 1);
    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        int pos = i, cyc = 0;
        fill(all(w), 0);
        for (int j = 1; j <= n; ++j) {
            pos = p[pos];
            w[j] = w[j - 1] + c[pos];
            cyc++;
            if (pos == i)
                break;
        }
        ll max_all = *max_element(&w[1], &w[cyc + 1]);
        ll max_mod = *max_element(&w[1], &w[k % cyc + 1]);
        ll t = max_mod;
        if (k >= cyc) {
            chmax(t, max_all);
            chmax(t, (k / cyc) * w[cyc] + (k % cyc == 0 ? 0LL : max(0LL, max_mod)));
            chmax(t, ((k / cyc) - 1) * w[cyc] + max_all);
        }
        chmax(ans, t);
    }
    return ans;
}

ll solve2() { // slow speed
    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        ll t = 0;
        for (int j = 0; j < k; ++ j) {
            pos = p[pos];
            t += c[pos];
            chmax(ans, t);
        }
    }
    return ans;
}

void input() {
    cin >> n >> k;
    p.resize(n);
    c.resize(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) {
        cin >> c[i];
    }
}

void make_data() {
    n = rand() % 10 + 1;
    k = rand() % 10 + 1;
    p.resize(n);
    c.resize(n);
    rep(i, n) {
        p[i] = i;
    }
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(all(p), engine);
    rep(i, n) {
        c[i] = pow(-1, rand() % 2) * rand();
    }
}

void output() {
    cout << n << " " << k << endl;
    rep(i, n) {
        cout << p[i] << " ";
    }
    cout << endl;
    rep(i, n) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    // srand((unsigned)time(NULL));
    input();
    // rep(i, 10) {
    // make_data();
    // output();

    cout << solve1() << endl;
    cout << solve2() << endl;

    // }

    return 0;
}

/* 
7 10
7 3 2 1 6 4 5 
-1497107446 558568677 -430845935 -1669199098 1716743255 2072972981 -1845705776 
2567420152
3789716236
*/