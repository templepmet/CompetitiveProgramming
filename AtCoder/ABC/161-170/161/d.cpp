#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

vector<ll> v;

int main() {
    int cnt = 0;
    int k;
    cin >> k;
    queue<string> q;
    for (int i = 1; i <= 9; ++i) {
        q.push(to_string(i));
    }
    while (cnt < 100000) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string t = q.front();
            q.pop();
            cnt++;
            v.push_back(atol(t.c_str()));
            int m = t.size();
            q.push(t + (char)(t[m - 1]));
            if (t[m - 1] != '0')
                q.push(t + (char)(t[m - 1] - 1));
            if (t[m - 1] != '9')
                q.push(t + (char)(t[m - 1] + 1));
        }
    }

    sort(v.begin(), v.end());

    cout << v[k - 1] << endl;

    return 0;
}