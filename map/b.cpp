#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

map<ll, ll> m;

ll n, p, q;

ll get(ll n) {
    if (n == 0) {
        return 1;
    }
    if (m[n]) {
        return m[n];
    }
    ll x = get(n / p) + get(n / q);
    m[n] = x;
    return m[n];
}

int main() {
    cin >> n >> p >> q;

    cout << get(n);

    return 0;
}