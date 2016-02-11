#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const int MAX = (int) 1e6;
const double eps = 1e-9;

map<int, int> m;
int a[MAX];

int f(int n) {
    if (n < MAX) {
        return a[n];
    }
    if (m[n] > 0) {
        return m[n];
    }
    if (n % 3 == 0) {
        m[n] = f(n / 3) + 5;
    }
    else {
        m[n] = f(n - 4) + 2;
    }
    return m[n];
}

int main() {
    int n;
    cin >> n;

    a[0] = -INF;
    a[1] = 0;
    a[2] = -INF;
    a[3] = 5;
    a[4] = -INF;

    for (int i = 5; i < MAX; i++) {
        if (i % 3) {
            a[i] = a[i - 4] + 2;
        } else {
            a[i] = min(a[i - 4] + 2, a[i / 3] + 5);
        }
    }

    int x = f(n);
    if (x < 0) {
        x = 0;
    }

    cout << x;
    return 0;
}