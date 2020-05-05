#include <iostream>

using namespace std;

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;

    return 0;
}