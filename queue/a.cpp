#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll a, b, c, x;
const ll mod = 1000000;
ll ans;

queue<ll> q;
deque<ll> minq;

int main() {
    cin >> n >> a >> b >> c >> x;
    for (int i = 0; i < n; i++) {
        x = ((a * x * x + b * x + c) / 100) % mod;
        if (x % 5 < 2) {
            if (q.size() > 0) {
                if (minq.front() == q.front()) {
                    minq.pop_front();
                }
                q.pop();
            }
        } else {
            while (minq.size() > 0 && minq.back() > x) {
                minq.pop_back();
            }
            minq.push_back(x);
            q.push(x);
        }
        if (minq.size() > 0) {
            ans += minq.front();
        }
    }

    cout << ans;

    return 0;
}