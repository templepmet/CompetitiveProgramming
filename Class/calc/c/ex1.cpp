#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int i, j, *p, A[10], (*b)[10], *C[10];
    i = 0;
    while (i < 10) { A[i] = i; i++; }
    b = &A;
    j = (*b)[5];
    printf("%d\n", j);
    (*b)[5] = 6;
    printf("%d\n", A[5]);
    p = A;
    printf("%d\n", *p);
    printf("%d\n", *(p + 3));
    printf("%d\n", p[3]);
    p = &A[1];
    C[0] = p;
    printf("%d\n", *C[0]);
    *C[0] = 11;
    printf("%d\n", A[1]);

    return 0;
}