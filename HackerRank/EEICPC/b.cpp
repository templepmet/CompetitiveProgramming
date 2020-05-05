#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD 1000000007
#define EPS 1e-10

using ll = long long;

int main() {
    int n, k;
    char c;
    cin >> n >> k;
    stack<pair<char, int>> s;
    pair<char, int> t;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (!s.empty()) {
            t = s.top();
            if (t.first == c) {
                s.pop();
                t.second++;
                if (t.second != k)
                    s.push(t);
            }
            else {
                s.push(make_pair(c, 1));
            }
        }
        else {
            s.push(make_pair(c, 1));
        }
    }
    string ss = "";
    while (!s.empty()) {
        t = s.top();
        s.pop();
        while (t.second--) {
            ss += t.first;
        }
    }
    if (ss.size() == 0)
        cout << "EMPTY!" << endl;
    else {
        reverse(ss.begin(), ss.end());
        cout << ss << endl;
    }

    return 0;
}