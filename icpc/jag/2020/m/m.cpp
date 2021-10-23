#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
double x[100];
double y[100];
double r[100];

double dot(double a[2], double b[2]) {
    return (a[0] * b[0]) + a[1] * b[1];
}

double distance(double a[2], double b[2]) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

bool isInterCirLine(int a, double s[2], double e[2]) {
    double v[2] = { e[0] - s[0], e[1] - s[1] };
    double c[2] = { x[a] - s[0], y[a] - s[1] };
    double cc[2] = { x[a], y[a] };
    double n1 = dot(v, c);
    if (n1 < 0) {
        return (distance(s, cc) < r[a] ? true : false);
    }
    double n2 = dot(v, v);
    if (n1 > n2) {
        double len = pow(distance(e, cc), 2);
        return (len < pow(r[a], 2) ? true : false);
    }
    else {
        double n3 = dot(c, c);
        return (n3 - (n1 / n2) * n1 < pow(r[a], 2) ? true : false);
    }
}

vector<vector<double>> inter(int a, int b) {
    double l2 = pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2);
    double l = sqrt(l2);
    double th = atan2(y[b] - y[a], x[b] - x[a]);
    double c = (l2 + r[a] * r[a] - r[b] * r[b]) / (2 * l * r[a]);
    double alp = acos(c);
    vector<vector<double>> ret;
    ret.push_back(vector<double>{x[a] + r[a] * cos(th + alp), y[a] + r[a] * sin(th + alp)});
    ret.push_back(vector<double>{x[a] + r[a] * cos(th - alp), y[a] + r[a] * sin(th - alp)});
    return ret;
}

double pp[101][2][2];
double dp[202][202];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    pp[0][0][0] = pp[0][1][0] = x[0];
    pp[0][0][1] = pp[0][1][1] = y[0];
    for (int i = 0; i < n - 1; ++i) {
        auto p = inter(i, i + 1);
        for (int j = 0; j < 2; ++j) {
            pp[i + 1][j][0] = p[j][0];
            pp[i + 1][j][1] = p[j][1];
        }
    }
    pp[n][0][0] = pp[n][1][0] = x[n - 1];
    pp[n][0][1] = pp[n][1][1] = y[n - 1];

    int m = 2 * (n + 1);
    fill(dp[0], dp[m], 1e18);
    for (int i = 0; i < m; ++i)
        dp[i][i] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    bool f = true;
                    for (int k = i; k <= j; ++k) {
                        if (!isInterCirLine(k, pp[i][a], pp[j][b]))
                            f = false;
                    }
                    if (f)
                        dp[2 * i + a][2 * j + b] = distance(pp[i][a], pp[j][b]);
                }
            }
        }
    }

    for (int k = 0; k < m; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[0][m - 1] << endl;

    return 0;
}