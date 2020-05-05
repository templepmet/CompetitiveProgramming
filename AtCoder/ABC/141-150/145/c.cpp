#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, a[8], k = 0;
    double x[8], y[8], sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        a[i] = i;
    }
    do {
        for (int i = 0; i < n - 1; ++i) {
            sum += sqrt(pow(x[a[i]] - x[a[i + 1]], 2) + pow(y[a[i]] - y[a[i + 1]], 2));
        }
        k++;
    } while(next_permutation(a, a + n));
    cout << fixed << setprecision(10);
    cout << sum / k << endl;

    return 0;
}