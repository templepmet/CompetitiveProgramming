#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define PI 3.14159265358979

#define MAXN 9
#define W 4

double f(double x) {
    // return pow(sin(2 * PI * x), 2);
    // return 1 / (1 + x * x * x);
	return sqrt(1 - x * x);
}

double conv(double th) {
	double ret = 1;
	ret *= tanh(sinh(th) * PI / 2);
	ret *= cosh(th) * PI / 2;
	ret /= pow(cosh(sinh(th) * PI / 2), 2);
	return ret;
}

void exp_conv(double ) {

}

void calc(double I[MAXN][W], double a, double b) {
	I[0][0] = 2;
	I[0][1] = (f(a) + 2 * f((a + b) / 2) + f(b)) / 4;
	for (int i = 1; i < MAXN; ++i) {
		double n = I[i - 1][0];
		double nn = n * 2;
		double J = 0;
		for (int j = 1; j <= n; ++j) {
			J += f(a + (b - a) / n * j - (b - a) / nn);
		}
		J = J * 2 / nn;
		
		I[i][0] = nn;
		I[i][1] = (I[i - 1][1] + J) / 2; // 台形公式
		I[i][2] = I[i][1] - I[i - 1][1]; // 差分
		I[i][3] = (I[i][1] - I[i - 1][1] / 4) * 4 / 3; // シンプソン
	}
}

int main() {
	double ans[MAXN][W] = {};
	vector<double> exp;
	calc(ans, 0, 1);

	for (int i = 0; i < MAXN; ++i) {
		printf("%3d %10.6f %12.6e %10.6f\n", (int)ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}

	return 0;
}