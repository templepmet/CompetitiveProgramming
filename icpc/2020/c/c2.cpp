#include <bits/stdc++.h>

using namespace std;

using ll = long long;

map<ll, int> prime(ll p) {
    map<ll, int> ret;
    ll n = p;
    int cnt = 0;
    for (ll i = 2; i * i <= p; ++i) {
        while (n % i == 0) {
            ret[i]++;
            cnt++;
            n /= i;
        }
    }
    if (n != 1) {
        ret[n]++;
        cnt++;
    }
    for (int i = 0; i < 3 - cnt; ++i) {
        ret[1]++;
    }
    return ret;
}

int main() {
    ll p;
    while (cin >> p && p > 0) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        q.push(1);
        q.push(1);
        q.push(1);
        auto mp = prime(p);
        ll a, b, c, v;
        for (auto it = mp.end(); it != mp.begin(); --it) {
            auto t = *it;
            // if (t.second > 2) {
            // a = q.top(); q.pop();
            // b = q.top(); q.pop();
            // c = q.top(); q.pop();
            // v = pow(t.first, (t.second / 3));
            // a *= v;
            // b *= v;
            // c *= v;
            // q.push(a);
            // q.push(b);
            // q.push(c);
            // }
            for (int i = 0; i < t.second; ++i) {
                a = q.top();
                q.pop();
                q.push(a * t.first);
            }
        }
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        c = q.top(); q.pop();
        cout << a + b + c << endl;
    }

    return 0;
}