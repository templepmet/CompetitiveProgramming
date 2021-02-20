#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int i, j, (*p)[4], B[5][4];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 4; j++)
            B[i][j] = 10 * i + j;
    p = B;
    auto t = *(p + 1);
    auto a = (p + 1)[1];
    printf("%d\n", *(* p+2));
    printf("%d\n", (*(p+1))[1]);
    printf("%d\n", *(p+1)[1]);
    printf("%d\n", **(p+1));

    return 0;
}