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

int main() {
    int seq[2], *ip, tmp;
    seq[0] = 5; seq[1] = 10; ip = seq + 1; tmp = 0;
    tmp = --*ip;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);
    
seq[0] = 5; seq[1] = 10; ip = seq + 1; tmp = 0;
    tmp = *--ip;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);

    seq[0] = 5; seq[1] = 10; ip = seq + 1; tmp = 0;
    tmp = *ip--;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);

    return 0;

    tmp = ++*ip;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);
    seq[0] = 5; seq[1] = 10; ip = seq; tmp = 0;
    tmp = *++ip;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);
    
    seq[0] = 5; seq[1] = 10; ip = seq; tmp = 0;
    tmp = *ip++;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);
    
    seq[0] = 5; seq[1] = 10; ip = seq; tmp = 0;
    tmp = *(ip++);
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);
    
    seq[0] = 5; seq[1] = 10; ip = seq; tmp = 0;
    tmp = (*ip)++;
    printf("ip:%p, tmp:%d, seq[0]:%d, seq[1]:%d\n", ip, tmp, seq[0], seq[1]);


    return 0;
}