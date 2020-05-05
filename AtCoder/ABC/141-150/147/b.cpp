#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0, l = s.size(); i < l / 2; ++i) {
        if (s[i] != s[l - i - 1])
            ans++;
    }
    cout << ans << endl;

    return 0;
}