#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000;
const int N = MOD + 10;

int n;
ll a, b, c, x;

ll s[N];
int ptr = 0;

ll ans = 0;
ll m = N;

int main() {
    cin >> n >> a >> b >> c >> x;

    for (int i = 0; i < n; i++) {
        x = ((a * x * x + b * x + c) / 100) % MOD;
        if (x % 5 < 2) {
            if (ptr > 0) {
                ptr--;
                if (ptr > 0) {
                    ans += s[ptr - 1];
                }
            }
        } else {
            if (ptr == 0) {
                m = x;
            } else {
                m = min(x, s[ptr - 1]);
            }
            ans += m;
            s[ptr] = m;
            ptr++;
        }
    }

    cout << ans;

    return 0;
}