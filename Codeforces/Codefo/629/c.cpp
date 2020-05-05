#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int h[3][3][2] = { 
    {{1, 2}, {2,1}, {0,0}},
    {{0,1},{1,0},{2,2}},
    {{0,2},{1,1},{2,0}}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string x;
        cin >> n >> x;
        string a(n, '0'), b(n, '0');
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (x[j] == '0') {
                a[j] = '0';
                b[j] = '0';
            }
            else if (x[j] == '1') {
                a[j] = '0';
                b[j] = '1';
            }
            else {
                if (j == 0) {
                    a[j] = '1';
                    b[j] = '1';
                }
                else {
                    if (flag) {
                        a[j] = '1';
                        b[j] = '1';
                    }
                    else {
                        a[j] = '0';
                        b[j] = '2';
                    }
                }
            }
            if (flag && a != b) {
                if (a < b)
                    swap(a, b);
                flag = false;
            }
        }
        cout << a << endl << b << endl;
    }

    return 0;
}