#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD 1000000007
#define EPS 1e-10

using ll = long long;

int main() {
    string day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    string s;
    cin >> s;
    cout << 7 - (find(day, day + 7, s) - day) << endl;

    return 0;
}