#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

bool isok(int x) {
    return true; // or false
}

int n;

// 定義
// lは常に条件を満たさない
// rは常に条件を満たす

// l=0で条件を満たすかも→絶対に条件を満たさない初期値l=-1
// r=n-1で条件を満たさないかも→絶対に条件を満たす？r=n

// m = (l + r) / 2 = l + (r - l) / 2より、r - l > 1の間mが更新される
// lは条件を満たさない最大の値
// rは条件を満たす最小の値

int binary_search() {
    int l = -1, r = n, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (isok(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;
}

int main() {
    

    return 0;
}

// https://qiita.com/drken/items/97e37dd6143e33a64c8c