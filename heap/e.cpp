#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;
const double eps = 1e-9;

int main() {
    int tests, n, k, t;
    string s;

    cin >> tests;
    for (int test = 0; test < tests; test++) {
        cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == "print") {
                cout << res << "\n";
            } else {
                cin >> t;
                if (pq.size() < k) {
                    pq.push(t);
                    res ^= t;
                } else {
                    if (pq.top() < t) {
                        res ^= pq.top();
                        res ^= t;
                        pq.pop();
                        pq.push(t);
                    }
                }
            }
        }
    }

    return 0;
}