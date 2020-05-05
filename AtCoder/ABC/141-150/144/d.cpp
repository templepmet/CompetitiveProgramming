#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.14159265359

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double th = atan2(b, a), area = x / a;
    double l = 0, r = PI / 2;
    for (int i = 0; i < 1000; ++i) {
        double ang = (l + r) / 2, maxa;
        if (ang < th) {
            maxa = a * b - a * a * 0.5 * tan(ang);
        }
        else {
            maxa = b * b * 0.5 / tan(ang);
        }
        if (maxa < area) {
            r = ang;
        }
        else {
            l = ang;
        }
    }
    cout << fixed << setprecision(10);
    cout << l * 180 / PI << endl;

    return 0;
}