#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

map<ll, ll> m;

ll f(ll n) {
    if (n <= 2) {
        return 1;
    }
    auto it = m.find(n);
    if (it != m.end()) {
        return it->second;
    }
    if (n % 2 == 1) {
        m[n] = (f(6 * n / 7) + f(2 * n / 3)) % (1ll << 32);
    } else {
        m[n] = (f(n - 1) + f(n - 3)) % (1ll << 32);
    }
    return m[n];
}

int main() {
    ll n;
    cin >> n;

    cout << f(n);

    return 0;
}