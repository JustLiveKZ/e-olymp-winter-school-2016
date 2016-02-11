#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

set<int> s;

ll ans = 0;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    int n;
    int t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        pq.push(t);
    }

    while (pq.size() >= 2) {
        ll top1 = pq.top();
        pq.pop();
        ll top2 = pq.top();
        pq.pop();
        ans += top1 + top2;
        pq.push(top1 + top2);
    }

    cout << ans;

    return 0;
}