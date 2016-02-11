#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

ll n, k, t;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (pq.size() < k) {
            pq.push(t);
        } else {
            ll top = pq.top();
            pq.pop();
            pq.push(top + t);
        }
    }

    while (pq.size() > 1) {
        pq.pop();
    }

    cout << pq.top();

    return 0;
}