#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(0, a - b * 2) << endl;

    return 0;
}