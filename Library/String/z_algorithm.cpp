#include <bits/stdc++.h>

using namespace std;

vector<int> z_algo(string s) {
    int l = s.size(), k;
    vector<int> z(l);
    z[0] = l;
    for (int i = 1, j = 0; i < l;) {
        while (i + j < l && s[j] == s[i + j]) j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        for (k = 1; k < j && k + z[k] < j; ++k) {
            z[i + k] = z[k];
        }
        i += k;
        j -= k;
    }
    return z;
}